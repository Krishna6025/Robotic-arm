#include <PCA9685.h>

#include <Wire.h>
//#include <Adafruit_MS_PWMServoDriver.h>
#include <SoftwareSerial.h>

Adafruit_MS_PWMServoDriver pwm = Adafruit_MS_PWMServoDriver();
SoftwareSerial Bluetooth(0, 1); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos; // current position
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos; // previous position
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50]; // for storing positions/steps
int speedDelay = 20;
int index = 0;
String dataIn = "";

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);  // Set frequency to 60 Hz (for servos)

  // Robot arm initial position
  servo1PPos = 90;
  setServoPosition(0, servo1PPos);
  servo2PPos = 150;
  setServoPosition(1, servo2PPos);
  servo3PPos = 35;
  setServoPosition(2, servo3PPos);
  servo4PPos = 140;
  setServoPosition(3, servo4PPos);
  servo5PPos = 85;
  setServoPosition(4, servo5PPos);
  servo6PPos = 80;
  setServoPosition(5, servo6PPos);

  Bluetooth.begin(9600); // Default baud rate of the Bluetooth module
  Bluetooth.setTimeout(1);
  delay(20);
}

void loop() {
  // Check for incoming data
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();
    Serial.println(dataIn);

    // Move Servo 1
    if (dataIn.startsWith("s1")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo1Pos = dataInS.toInt();
      moveServo(0, servo1PPos, servo1Pos);
      servo1PPos = servo1Pos;
    }

    // Move Servo 2
    if (dataIn.startsWith("s2")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo2Pos = dataInS.toInt();
      moveServo(1, servo2PPos, servo2Pos);
      servo2PPos = servo2Pos;
    }

    // Move Servo 3
    if (dataIn.startsWith("s3")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo3Pos = dataInS.toInt();
      moveServo(2, servo3PPos, servo3Pos);
      servo3PPos = servo3Pos;
    }

    // Move Servo 4
    if (dataIn.startsWith("s4")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo4Pos = dataInS.toInt();
      moveServo(3, servo4PPos, servo4Pos);
      servo4PPos = servo4Pos;
    }

    // Move Servo 5
    if (dataIn.startsWith("s5")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo5Pos = dataInS.toInt();
      moveServo(4, servo5PPos, servo5Pos);
      servo5PPos = servo5Pos;
    }

    // Move Servo 6
    if (dataIn.startsWith("s6")) {
      String dataInS = dataIn.substring(2, dataIn.length());
      servo6Pos = dataInS.toInt();
      moveServo(5, servo6PPos, servo6Pos);
      servo6PPos = servo6Pos; 
    }

    // If button "SAVE" is pressed
    if (dataIn.startsWith("SAVE")) {
      servo01SP[index] = servo1PPos;  
      servo02SP[index] = servo2PPos;
      servo03SP[index] = servo3PPos;
      servo04SP[index] = servo4PPos;
      servo05SP[index] = servo5PPos;
      servo06SP[index] = servo6PPos;
      index++;                        
    }

    // If button "RUN" is pressed
    if (dataIn.startsWith("RUN")) {
      runservo();  
    }

    // If button "RESET" is pressed
    if (dataIn == "RESET") {
      memset(servo01SP, 0, sizeof(servo01SP));
      memset(servo02SP, 0, sizeof(servo02SP));
      memset(servo03SP, 0, sizeof(servo03SP));
      memset(servo04SP, 0, sizeof(servo04SP));
      memset(servo05SP, 0, sizeof(servo05SP));
      memset(servo06SP, 0, sizeof(servo06SP));
      index = 0;  
    }
  }
}

void moveServo(int servoIndex, int startPos, int targetPos) {
  if (startPos > targetPos) {
    for (int j = startPos; j >= targetPos; j--) {
      setServoPosition(servoIndex, j);
      delay(1);
    }
  } else {
    for (int j = startPos; j <= targetPos; j++) {
      setServoPosition(servoIndex, j);
      delay(1);
    }
  }
}

void setServoPosition(int servoIndex, int position) {
  int pulseWidth = map(position, 0, 180, SERVOMIN, SERVOMAX); // Adjust according to your servo specifications
  pwm.setPWM(servoIndex, 0, pulseWidth);
}

void runservo() {
  while (dataIn != "RESET") {   
    for (int i = 0; i <= index - 2; i++) {
      if (Bluetooth.available() > 0) {
        dataIn = Bluetooth.readString();
        if (dataIn == "PAUSE") {
          while (dataIn != "RUN") {
            if (Bluetooth.available() > 0) {
              dataIn = Bluetooth.readString();
              if (dataIn == "RESET") {     
                break;
              }
            }
          }
        }

        if (dataIn.startsWith("ss")) {
          String dataInS = dataIn.substring(2, dataIn.length());
          speedDelay = dataInS.toInt(); // Change servo speed (delay time)
        }
      }
      
      // Run through each servo for saved positions
      for (int servoIndex = 0; servoIndex < 6; servoIndex++) {
        moveServo(servoIndex, servo01SP[i], servo01SP[i + 1]);
      }
    }
  }
}

# Robotic-Arm
5-Degree of Motion robotic arm using servo motors and Arduino Uno. It can be used for various stationary applications and has pre-set movements to perform repeated actions.<br/>

This documentation is for a 5DOF robotic arm developed using various online resources.<br/>

Essential Prerequisites:<br/>
1)Arduino Uno with HC-05 Bluetooth module.<br/>
2)Four 10kg MG995 servos and one SG90 servo.<br/>
3)Android app to control the arm's motion.<br/>
4)Body for the arm.<br/>
The Arduino code was written using version 2.3.3 of the IDE. The servo shield PCA9685, an I2C board with 16 channels, is powered by two 18650 3.3V rechargeable batteries. <br/>The primary purpose of using the servo shield is to provide sufficient current to the MG995 servos, which the Arduino alone cannot handle simultaneously.<br/>

The controller for the arm is an Android app developed using [MIT App Inventor](https://appinventor.mit.edu/). The code blocks for the app were inspired by the blog [How to Mechatronics](https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/). <br/>The APK for the app is available in the repository for download and can be installed on any Android (8+) phone. The values for the arm can be adjusted by uploading the configuration file to the website.<br/>

The structure of the arm is 3D-printed using PLA material. The CAD files for this model were sourced from Kelton of the [Build Some Stuff YouTube channel](https://www.youtube.com/@buildsomestuff). These files are freely available on [Printables](https://www.printables.com/model/818975-compact-robot-arm-arduino-3d-printed) for download and should also be in this repository. If not, please contact me for the STL file.<br/>

# Challenges
The main challenges faced during the development of the arm were:<br/>

Bluetooth Connection: Pre-existing apps on the Play Store could not connect to the HC-05, so a custom app had to be developed, which took considerable time.<br/>
Power Source: As I intended for the arm to remain stationary, I opted to power the Arduino with a USB-B connection while the servo shield is powered by rechargeable batteries.<br/>
<br/><br/>

# Installation<br/>
Following the circuit diagram and the instructions from the video assembling the Arm is simple. The main hinderence is the varity of screws used in the build.

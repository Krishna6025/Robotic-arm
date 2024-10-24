# Robotic-Arm
5-Degree of motion robotic arm using servo motors and Arduino Uno. It can be used for many purposes in a stationary scene along with having pre-set moments to do any repeated moments
<br/>

This documantation is for a 5DOF Robotic arm that has been made using many online resources.<br />
The essential prerequisets of this project are:
<br/>
1)Arduino Uno with HC-05 bluetooth module<br/>
2)4 10kg MG995 servos along with 1 SG90 servo.<br/>
3)Android app to control the motion of the Arm.<br/>
4)Body for the Arm.<br/><br/>

The Arduino code was written 2.3.3 version of the IDE. The servo sheild PCA9685 which is a I2C board with 16 channel which is powered using 2-18650 3.3v rechagable battery. The main purpose of having the servo sheild is to provide enough current to the MG995 servos which the Arduino cannot handle at once.<br/>
<!-- write about HC-05-->
<!-- include pics of servo-->
The controller for the Arm is an Android app which was made using [mit app inventer ](https://appinventor.mit.edu/). The code blocks for the app was taken from the blog of [How to mechatronics](https://howtomechatronics.com/tutorials/arduino/diy-arduino-robot-arm-with-smartphone-control/) The APK for the app is present in the repo that can be downloaded and installed in any Android(8+) phone. The values for the arm can be tweeked by uploding the file to the website.<br/>


The structure of the Arm is 3-D printed with PLA material.
The CAD files for this model was taken from a fellow robotic enthusisat Kelton of 
[Build Some Stuff youtube channel](https://www.youtube.com/@buildsomestuff). These files are present on https://www.printables.com/model/818975-compact-robot-arm-arduino-3d-printed website for free download. They should also be present in this repo (in case), if not message me for the STL file.
<br /><br/>

<!--circuit diagram graphically-->
# Challenges

The setbacks faced in the making of the Arm started with the bluetooth connection. The preexisting apps present in the playstore could not connect my HC-05 hence we had to go with the custom app which took a lot of time.<br/>
The second challenge was the power source for the Arm. As i wanted this Arm in a statinary place i opted to power the Arduino with USB B and the servo sheild is powered with rechargeable battery.<br/>




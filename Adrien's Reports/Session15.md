# Session report 15: March 29, 2024

**Session objective:** Enable 2 movements trajectory to reach any coordinates on the playfield. Switch from an Arduino to an ESP32 on the robot. Find new lenses for our cameras.

## Finding new lenses for our cameras
One of the main problems at Eurobot's competition, is wifi waves interferences. So we were worried about positionning a camera on the calculation zone support, cause our communications would be easily disrupted or delayed. As our cameras are the main sensors of the robot, we decided for safety reasons to put all of  them on the robot. But the lenses provided with JevoisPro cameras have an angle near 60° so even with our 4 cameras we wouldn't be able to cover 360°.

To solve this, we decided to change our lenses for fish eyes ones which deform the image to allow huge angles sight. We chose 120° wide angle lenses to have redundancy as our cameras will be tilted towards.

## Take in hand the ESP32 chip to replace our Arduino Mega with a more powerful chip

I chosed to replace the Arduino Mega for an ESP32 for many reasons : 
- ESP32 has a higher clock speed, up to 240Mhz compared to 16 MHz for the Arduino Mega, so we will be able to have a higher sampling frequency.
- It can process to multiple tasks at the same time (for example to deploy an actuator while moving).
- It has WIFI and Bluetooth integrated, so it will be easier to send commands to configure it before making it fully autonomous.

First, we need to install the USB driver, its name can be easily identified on windows device manager and then we can downloaded from internet.
I wanted to be able to programm it with Arduino IDE, so to be able to do this, i searched for ESP32 board package by Espressif in the arduino software. 
Finally with both package and driver installed, we can easily upload code to it by selectionning the board and COM port in the Arduino menu.
Be awared that it's only possible to upload a code on it while it's in boot mode. So, to exit boot mode, on some ESP32, you need to press the boot button for few seconds while the programm is being uploaded.

## Recalibrate the robot's odometry
As a new version of the rolling base has been assembled, i had to recalibrate the odometry to be able to continue working on the displacements algorithm. To do this, i first recalibrated the robot for rotations, by reading the values from each encoder after manually doing a 360° rotation around a nail (thanks to a wood calibration part temporarily fixed on the robot which has an hole at the cinematic center of the robot). 
Ad then calibrate linear odometry by moving the robot in straight line (by pushing it forward leaning it against a wall) and reading both the values of the encoders and the distance travelled on a rule.

Linear calibration : 

<img src="Report's images\Session15\linear_calibration.jpg" width="400">


## Next session tasks
Finalize adjusting the current Arduino code to ESP32 by adding an interruption to replace millis() used for sampling. Find correct PID coefficients. Work on data transfer between ESP32 and the Jetson Nano, and between the Jetson Nano and our four cameras.
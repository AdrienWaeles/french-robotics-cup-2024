# Session report 16: April 9, 2024

**Session objective:** Switch from the Arduino Mega to an ESP32 on the robot. Etablish a connection between the Nvidia Jetson and the cameras. Optimize the closed loop control algorithm by setting a timer on the ESP32 to sample.

## Problem with serial communication with ESP32
After successfully transfering the program to the ESP32, it was constantly rebooting as the following message was continously printed on the console : 

rst:0x8 (TG1WDT_SYS_RESET),boot:0x13 (SPI_FAST_FLASH_BOOT)
configsip: 0, SPIWP:0xee
clk_drv:0x00,q_drv:0x00,d_drv:0x00,cs0_drv:0x00,hd_drv:0x00,wp_drv:0x00
mode:DIO, clock div:1
load:0x3fff0030,len:1344
load:0x40078000,len:13516
load:0x40080400,len:3604
entry 0x400805f0
ets Apr 9 2024 09:22:53

After some researchs i found out that on a classic ESP32 there are 6 pins which are used by internal Flash and thus musn't be connected to anything. So the problem was simply solved by switching the cables on other pins based on ESP32 Pinout diagramm which can be found on internet.

## Test of an encoder with ESP32
Then I wired an Encoder to the ESP32 to verify it is still working as ESP32 works only with 3.3V signals so it may be incompatible with some numerical devices if they threashold is superior at 3.3V.
<img src="Report's images\Session16\ESP32_encoder_wiring.jpg" width="400">

## Next session tasks
We have finally received all the components to be able to assemble the final version of the robot, so next session should be fully consacred to the calibration of the PID and optimizing the robot's displacements. Finally i will implement curved trajectories which will be necessary to avoid obstacles properly without loosing too much time.
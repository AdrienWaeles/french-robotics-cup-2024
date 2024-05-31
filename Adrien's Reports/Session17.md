# Session report 17: April 16, 2024

**Session objective:** Create the wiring diagram of our main robot, wire cables on the final version of our robot, add programm actuators sequences.

## Wiring diagram
First, as during the competition we will probably need to do maintainance on the robot, to avoid loosing time with wiring, I created a wiring diagram on the software Fritzing. Older versions of this software can be downloaded for free here : arduinofactory.fr/telecharger-fritzing-gratuitement-et-legalement.
This diagramm will also be used by Teo Baillot, a member of the team who is in charge of the cable management of the robot and who will weld cables on the final version to avoid having cables unplugging on the robot during a match.

<img src="Report's images/Session17/Wiring_PolyMartian_bb.png" width="400">

Two Lipos batteries are 3s 35C 2200mAh. 3S means the battery is made with 3 cells, so as each cell provides 3.7V, a 3S battery provides a voltage of 3*3.7V = 11.1V. So we put two batteries in serie to obtain a voltage around 22V which is perfect for our DC motors. 
We decided to put two more Lipos in parallel as we want to be sure that we will have enough capacity and so if we have a problem with a pair of batteries the robot will be able to continue his work with the others two batteries.

An emergency stop button is directly wired between the Lipos and the motors to be able to stop the robot at any time if a problem occurs during the competition.

## Wiring on the robot
To avoid cables disconnecting during the competition, it was indispensable to weld all cables. Even with 2 people welding cables simunlateously, it took multiple hours as the connexions on the esp32 are really thin and as we had only 0.75mm² cable. Hopefully, we made the good decision to buy silicone cables which are really convenient to weld cause they are very flexible and overall heat resistant.

But after that, we still needed to do some modifications on the robot or to modify wiring, and this experience showed us that wiring cables on a project which is aimed to be constantly modified was not the best solution. Thus, next year we will try to create our own cards with connectors for flat cables which are really convenient to disconect and reconnect and also very strong.

## ESP32 driver not foundable
One of our spare ESP32 wasn't recognized by my computer. I spent almost one hour searching for this driver and testing different ones who had the same reference indicated in the device manager or also by identifying the name of the USB to serial converter chip on the ESP32 (see infography below from Medium.com) <img src="Report's images/Session17/esp32_usb_uart_chip_fromMedium.png" width="400">
Our ESP32 was a copy from the original, and as i found no driver compatible with it, i wasn't able to make it work so i had to switch for another esp to not loose too much time.


## Wheel friction and weight repartition problem
Finally, now that the wiring was finished, i wanted to test the new rolling base with my closed loop control algorithm made previously but a problem occured. A wheel had too much friction compared to the other leading to bad trajectories. This was due to a free wheel which had friction with motor shaft.
The left wheel didn't grip correctly to the ground caused the inacurracy of some 3d printed part on the robot or its deformation. But this error is so small that it should be corrected when we will put weight on the robot with our batteries. Meanwhile, we can add counterweights on the robot to replace the future batteries.


## Next session tasks
Finalize the code of the robot to be ready for the robotics cup which will happen from 8th to 11th May 2024.
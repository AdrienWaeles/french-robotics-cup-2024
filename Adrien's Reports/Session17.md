# Session report 17: April 16, 2024

**Session objective:** Create the wiring diagram of our main robot, wire cables on the final version of our robot, add programm actuators sequences.

## Wiring diagram
First, as during the competition we will probably need to do maintainance on the robot, to avoid loosing time with wiring, I created a wiring diagram on the software Fritzing.
This diagramm will also be used by Teo Baillot, a member of the team who is in charge of the cable management of the robot and who will weld cables on the final version to avoid having cables unplugging on the robot during a match.

<img src="Report's images/Session17/Wiring_PolyMartian_bb.png" width="400">

Two Lipos batteries are 3s 35C 2200mAh. 3S means the battery is made with 3 cells, so as each cell provides 3.7V, a 3S battery provides a voltage of 3*3.7V = 11.1V. So we put two batteries in serie to obtain a voltage around 22V which is perfect for our DC motors. 
We decided to put two more Lipos in parallel as we want to be sure that we will have enough capacity and so if we have a problem with a pair of batteries the robot will be able to continue his work with the others two batteries.

An emergency stop button is directly wired between the Lipos and the motors to be able to stop the robot at any time if a problem occurs during the competition.

## Wiring on the robot
Then i wired cables on the final version of our robot. This wiring is of course still temporary and will be used to do tests on the robot without waiting for all cables to be welded correctly. This will also prevent bad suprises, cause we will be sure that our wiring is correct before welding cables.

## Wheel friction and weight repartition problem
Finally, now that the wiring was finished, i wanted to test the new rolling base with my closed loop control code previously made but a problem occurs. A wheel had too much friction compared to the others leading to bad trajectories. This was due to a free wheel which had friction with motor shaft.
The left wheel didn't grip correctly to the ground. This was probably due to the inacurracy of some 3d printed part on the robot or its deformation, but this error is so small that it should be corrected when we will put weight on the robot with our batteries.


## Next session tasks
Finalize the code of the robot to be ready for the robotics cup which will happen from 8th to 11th May 2024.
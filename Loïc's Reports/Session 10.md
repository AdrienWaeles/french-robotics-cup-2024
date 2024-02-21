# February 21, 2024
## Horyzontal guiding system
During this session, I modeled the horyzontal guiding system. I used the same method as for the vertical guiding system : 
- A horyzontal linear guide
- A horyzontal carriage
- A stepper motor to move the belt arround the pulley (not shown on the picture below)
- A belt to connect the stepper motor to the carriage

On the carriage, There is a part to hold the servo motor which will open and close a claw to prevent plants to fall when the robot is moving. The stepper motor on the right of the image below is mounted upside down to make the rest of the system more compact. The part which holds the stepper motor has a hole to let the belt pass through it as well as the guide.

<figure align="center">
    <img src="./src/session_10/horyzontal guide.jpg" height=300>
    <img src="./src/session_10/view2.jpg" height=300>
    <img src="./src/session_10/in context guide.jpg" height=300>
</figure>

> The horyzontal guiding system

Here are the steps the robot will do to move the plants from one place to another:
1. The robot arrive to one of the plants spot
2. The robot opens the claws
3. The robot moves forward to the plants until it surrounds them
4. The robot closes the claws
5. The robot moves slides the claws from the front to the back to make sure the plants are well held against the robot's frame
6. The robot moves to the other spot

To unload the plants, the robot will do the same steps but in reverse order.

I didn't had time to mount these parts on the robot but I will do it during the next session. Here are the printed parts:

<figure align="center">
    <img src="./src/session_10/printed parts.jpg" height=300>
</figure>

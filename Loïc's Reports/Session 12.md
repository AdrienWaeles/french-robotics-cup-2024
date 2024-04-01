# March 12, 2024
## Main robot
Two session ago, I modeled and printed the system which will hold the plants against the robot's frame. when I tried to mount them on the robot, I realized that the system was a little bit too long. I had to cut it and reassemble it. The difficulty was to cut the guide rail because it is made out of hardened steel so it cannot be cutted with a regular steel saw. Finally I found out that a [Dremel®]('https://www.dremel.com/fr/fr/p/dremel-8260-f0138260ja') with the right blade was able to cut through it whithout too much difficulties.

<div align="center">
    <img src="src/session_12/20240305_111355.jpg" width="300px">

    Cutted rail guide
</div>

## Ladybug robot
### Components
Last session, I chose the components for the ladybug robot. Before starting to model the ladybug itself, I modeled on SolidWorks the components that will be used in the robot. I modeled the DC motor, the servo motors and the DWM1001 module. I found the other components on the internet because they are standard. Here are the components I modeled myself on SolidWorks:

<div align="center">
    <img src="src/session_12/moteur dc.png" alt="DC motor" width="300px">

    DC motor
</div>
<div align="center">
    <img src="src/session_12/servo 1.png" alt="Servo motor" width="300px">

    Servo motor (for the direction)
</div>
<div align="center">
    <img src="src/session_12/servo 2.png" alt="Servo motor" width="300px">

    Servo motor (for the actuator), a bit smaller than the previous one
</div>
<div align="center">
    <img src="src/session_12/DWM1001.png" alt="Servo motor" width="300px">

    DWM1001 module
</div>

Here are the components I found on the internet ([GrabCAD]('https://grabcad.com/library')):
<div align="center">
    <img src="src/session_12/ultrasonic.png" alt="Servo motor" width="300px">

    Ultrasonic sensor
</div>
<div align="center">
    <img src="src/session_12/camera.png" alt="Servo motor" width="300px">

    Raspberry Pi camera
</div>
<div align="center">
    <img src="src/session_12/battery.png" alt="Servo motor" width="300px">

    18650 battery in a holder
</div>
<div align="center">
    <img src="src/session_12/bms.png" alt="Servo motor" width="300px">

    BMS (Battery Management System) for the 18650 battery and step-up module (3.7V to 5V)
</div>
<div align="center">
    <img src="src/session_12/raspberry.png" alt="Servo motor" width="300px">

    Raspberry Pi Zero W
</div>
<div align="center">
    <img src="src/session_12/switch.png" alt="Servo motor" width="300px">

    Emergency stop switch
</div>

### Chassis
For the chassis, I modeled it as compact and simple as possible. I designed it so that the DC motor is inside the chassis, so that its mass serves to stabilize the ladybug. The structure of the chassis is very rigid because of its geometry, when can see some holes on the top which are made to screw the other parts on it. Here is the design I came up with:

<div align="center">
    <img src="src/session_12/chassis.png" alt="Chassis" width="700px">

    Chassis (Top view)
</div>
<div align="center">
    <img src="src/session_12/chassis2.png" alt="Chassis" width="700px">

    Chassis (Bottom view)
</div>
<div align="center">
    <img src="src/session_12/chassis3.png" alt="Chassis" width="700px">

    Chassis (front view)
</div>

Then I added to the chassis the DC motor, the servo motor for the direction and the wheels. A small wheel is mounted on a fork which is attached to the servo motor. In order to transmit the rotational power from the DC motor to the wheels, I designed a small gear system. The gear ratio is 1:1, so the wheels will rotate at the same speed as the DC motor which is already designed at the right speed. The wheels might be a little bit too much apart but I will see this detail later. Here is the chassis with the motors and the wheels:

<div align="center">
    <img src="src/session_12/chassis4.png" alt="Chassis" width="700px">

    Chassis with the DC motor, the servo motor and the wheels
</div>
#Session report 2

**Session objective:** Complete research on the most crucial physics constraints to consider in achieving a reliable rolling base for the prototyping of the next version. And begin work on the closed-loop control.

## Steps to implement odometry and feedback control 

First of all, I established an ordered list of tasks to enhance efficiency:

1) Ensure a high-performance mechanical system with optimal weight distribution, reliable coding wheels, and precise wheel placement. This aspect was thoroughly considered during and before the first session. We have now identified an excellent implementation, and Loic is currently working on the mechanical part.
2) Calibrate the odometry to determine the precise location of the robot on the table using the coding wheels. This system relies on four constants: coding wheel diameters, their spacing, encoder resolution, and the error related to the diameter difference between the two coding wheels.
3) Send a command and calculate errors between it and the estimated position based on the odometry.
4) Implement ramps to achieve progressive acceleration and deceleration.
5) Implement a PID (Proportional Integral Derivative) control system: Identify the optimal coefficients for Proportional, Integral, and Derivative terms to reach a value very close to the setpoint rapidly and without excessive oscillations.


As the coding wheels are still in the design phase, I have decided to prioritize continuing work on determining the maximum acceleration. This way, this aspect will be prepared for implementation once the rolling base is ready to conduct physics measurements.

##Measuring the buckling of the wheels and the play in the motor.

During the previous session, we observed lateral vibrations in the wheels. Therefore, this time, using a dial indicator, I measured the buckling of the wheels.

<img src="Report's images\Session02\Dial-Indicator_howItWorks_fromExtruDesign.png" width="300">

To use this tool, we have to magnetize it to a fixed surface to prevent shaking. Then, we simply position the plunger against the external surface of the wheel. Next, we delicately turn the wheel one complete revolution (or multiple turns for more precision). Afterward, we read the buckling on the graduated scale and divide it by the number of turns made. The precision of this instrument is approximately 0.01mm, which corresponds to the space between two marks on the scale.

With this tool, I measured a buckling of approximately 1mm per wheel, which is not insignificant but much less than I expected. Therefore, I believe it won't pose a significant obstacle to achieving precise odometry at the outset. That's why we have decided to retain these wheels, and we will consider replacing them with more precise ones only if they prove inadequate results.

##Encoder test and reflections on coding wheels

<img src="Report's images\Session02\motor_encoder_dismantled.jpg" width="300">


During this session, I also learned that a minuscule diameter difference between the two coding wheels can result in significant imprecision. This is because the coding wheels will register the same number of revolutions, leading us to believe that the robot is moving in a straight line. However, in reality, if one wheel has a smaller diameter, the robot will veer to one side.

To address this issue, we need to implement a coefficient to multiply the number of revolutions of one wheel by a certain factor. This compensates for the diameter difference, ensuring that both wheels cover an equal distance and register the correct movement.





##Mechanical calculations
Previously, we had discovered a method to determine the coefficient of adhesion for our wheels. Now, I have examined how, from this coefficient, we can deduce the maximum acceleration and deceleration achievable.

To achieve this, we require one more parameter: the location of the center of gravity. Since the robot is not fully designed at this stage, it's not practical to measure it now. However, I can prepare all the calculations so that we will only need to replace the value in the formula later on.


**Next session tasks:**
During the next session, I will continue preparing the robot displacement and odometry algorithms, as well as the necessary calculations, to be ready to begin work on the robot's position. If the new rolling base prototype, including the coding wheels, is ready, I will initiate the odometry calibration.
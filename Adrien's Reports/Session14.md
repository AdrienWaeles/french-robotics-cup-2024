# Session report 14: March 29, 2024

**Session objective:** Implement new speed PID corrections where the error is the difference between the estimated speed (which is this time calculated from a trapezoidal or triangular speed profile based on the position to be reached) and the actual speed of the robot.

## Reminder

During the previous sessions, I had written a function get_phases_distance() capable of estimating the duration of each phase (acceleration, constant speed, deceleration) needed to reach a specified distance, and another function get_speed_target() capable of determining the speed target to be reached at each instant based on this speed profile.

## Resolved issue with get_speed_target()
The function worked by comparing the remaining distance to travel with the distances needed to accomplish acceleration and deceleration phases to determine when to switch to the next phase. Each time it was invoked (based on sampling frequency), it incremented the speed target by either max_acceleration or max_deceleration, depending on the current phase.

However, this approach didn't work properly because there was no correlation between the sampling frequency at which acceleration was added and the distance traveled.

To address this issue, I modified the function to be based on phase durations rather than phase distances. For instance, the duration of the acceleration phase represents the number of times we need to increment the speed target by the max_acceleration coefficient to reach the desired maximum speed. So, each time get_speed_target() is called, I increment a time variable by one, representing the number of times max_acceleration has been added to the target speed and when this variable reaches the acceleration time calculated by the get_phases_distances() function, the system can switch to the constant speed phase.

## Adapting get_speed_target() for different speeds on each wheel
To enable the use of get_speed_target() for rotation or reverse movement, I've introduced two coefficients, one for each wheel. These coefficients are multiplied by the final speed target to yield a rotation speed for each wheel. Consequently, if the left coefficient is set to -1 and the right coefficient to 1, the robot will pivot in place.

## Calculating error
Calculating the error was quite tricky as we now have two errors: one for linear speed and the other for angular speed. Additionally, we have the integrals of these variables, which represent linear position and angular position.

To make it easier to understand, I decomposed the problem into three functions:

1) get_theorical_speed_and_position()
2) get_real_speed_and_position()
   
These two functions will be used to dermine 5 parameters :
The linear velocity of the robot :
$$V = leftSpeed + rightSpeed $$ 

Its angular velocity :
$$W = rightSpeedTarget - leftSpeedTarget$$ 

Its angle travelled (integral of the angular velocity) : 
$$Z = previousZ + W $$ 

Distance travelled on x axis (integral of x component of linear speed) :
$$X = previousX + V * cos(Z)$$ 

Distance travelled on y axis :
$$Y = previousY + V * sin(Z)$$ 

The difference between the two functions is that the first one will process these operations with theoretical values, which are determined relative to the speed profile, while the second one will process with real speeds determined using the encoders.

3) get_errors() which calls the two functions above to process the errors calculus (difference between theorical speed/position and real speed/position).
$$ errorDistance = \sqrt{( (Xtheorical - Xreal)² + (Ytheorical - Yreal)²} ) $$ euclidean norm to determine the distance between the points (Xtheorical, Ytheorical) and (Xreal, Yreal).

$$ errorAngle = atan2(Ytheorical - Yreal, Xtheorical - Xreal) - Zreal $$ trigonometric relation where atan2 is a mathematical function which process to arctan of the first paramater divided by the second one.

These two variables are used to calculate the errors we will use in our pid correction : 
$$ errorXY = errorDistance * cos(errorAngle) $$
$$ errorV = Vtheorical - Vreal  $$
$$ errorZ = Ztheorical - Zreal $$
$$ errorW = Wtheorical - Wreal $$

## Implementing the PID correction and send command to motors
Finally we are now able to create a function that will apply Proportional, Integral (and eventually Derivation if needed later) coefficients to our errors to send the resulting command to the motors. Of course we need two differents PID, one for linear speed : errorV and the other one for angular speed : errorW.

$$ pid_v = P_V * errorV +  I_V * errorXY $$
$$ pid_w = P_W * errorW +  I_W * errorZ $$

The resulting motors command are then : 
$$ LeftCommand = pid_v - pid_w $$
$$ RightCommand = pid_v + pid_w $$

## Next session tasks
- During next session, Loic will assemble the final version of the rolling base so after that i will have to recalibrate the robot and find the correct PID coefficients to verify everything is working correctly.
- Work on a way to send the data processed by our cameras to the Jetson. 

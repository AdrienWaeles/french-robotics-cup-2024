# Session report 11: March 05, 2024

**Session objective:** Learn more about PID to enhance our closed-loop control model, implement trapezoidal speed profiles, and conduct research on robot trajectories.

## Research on PID
Previously, I encountered issues with finding the optimum PID coefficients, so I dedicated time to conducting further research. Through this process, I gained valuable insights. All the articles that contributed to these conclusions will be linked in the sources section at the end of the document.

- Firstly, if my motors lack sufficient power to reach the final position, it may be due to the integral coefficient not being large enough. When the error becomes very small, the proportional corrector can struggle to make significant adjustments, as it essentially multiplies a number approaching zero by Kp. In such cases, the only effective correction method is to rely on the integral term, which will see its impact significantly amplified in steady-state.

- I also learned about the importance of selecting the optimal sampling frequency. The sampling frequency determines the interval at which measurements are taken from the encoders and corrections are applied with a PID controller. While it may be tempting to use a very high frequency to increase precision, this approach can lead to inaccuracies. Higher frequencies result in corrections being applied more frequently, but on less precise measurements, as the number of encoder steps measured at the sampling frequency will be lower for the same distance. Conversely, if the sampling frequency is too low, corrections will not be applied regularly enough, resulting in jerky movements.

- Finally, in the context of simple movements such as translations and rotations in robotics, it is common to use trapezoidal speed profiles. These profiles consist of a constant acceleration phase, followed by a phase of constant speed once the maximum speed is reached, and finally, a constant deceleration phase. This approach facilitates smooth movements and helps ensure precise odometry by minimizing slippage.

## Trajectory Planning
There are multiple routes to send the robot from one point to another, so I conducted research to identify the most suitable one for our case.

### 1. Circular Arcs:
The robot follows arcs of circles and straight lines to form a continuous trajectory. While mathematically straightforward, it exhibits C1 discontinuities, which can cause acceleration issues. Additionally, there are risks associated with centrifugal force during high-speed arc changes.

### 2. Bezier Curves:
A promising alternative due to their continuity (C1), but their mathematical complexity poses challenges in path planning. Dismissed due to the difficulties involved.

### 3. Clothoids:
A clothoid is a mathematical curve known for its linear increase in curvature, resembling a spiral shape. It is frequently employed in trajectory planning due to its smooth and continuous curvature changes, offering mechanical advantages, especially in robotics. Opting for a sequence of clothoid arcs ensures a curved trajectory for the robot, helping to avoid acceleration discontinuities and ensuring feasibility.

<img src="Report's images\Session11\clothoid.png" width="250">

### 4. Rotation followed by translation
After reviewing robotics cup replays from past years, I observed that most teams opt to avoid curved trajectories due to their complexity. Instead, they choose to use a sequence of independent rotations and translations to reach the desired points. While this approach may not seem optimal, even top-performing teams utilize it and achieve excellent results because it minimizes errors in position and centrifugal problems. Additionally, since distances to travel are relatively short in this competition, the difference in time between this method and previous ones is negligible. Therefore, considering the limited time remaining before the competition (only 2 months), I have decided to adopt this method for this year.


## Trapezoidal speed command
I dedicated the end of the session to researching how to implement a trapezoidal speed command to prevent wheel spinning both at the start and end of the robot's movement, ensuring that the setpoint is not exceeded. I explored various algorithms before selecting the most accurate and easy-to-implement method. Drawing from the experience of the Cubot Team, who generously shared their insights on their GitHub repository, I learned that this can be achieved by calculating the duration of each phase using kinematic equations, along with parameters such as maximum allowed speed, acceleration, deceleration coefficients and the target distance. With these durations determined, we can then determine the appropriate speed to send to each motor to reach the desired position throughout the three phases.

## **Next session tasks:**
In the upcoming session, I will implement trajectories to navigate coordinates and reach any point on the table. Additionally, I will simultaneously implement the trapezoidal speed profile.

## Sources :
https://github.com/VRAC-team/la-maxi-liste-ressources-eurobot/blob/master/asservissement/totofweb-PID_r%C3%A9gulation_de_position_vitesse.pdf

https://github.com/VRAC-team/la-maxi-liste-ressources-eurobot/blob/master/asservissement/TechTheTroll-trajectoire_courbe.pdf

https://github.com/VRAC-team/la-maxi-liste-ressources-eurobot/blob/master/asservissement/Cubot-atelier_asservissement.pdf

Cloithoid image from : https://en.wikipedia.org/wiki/Euler_spiral

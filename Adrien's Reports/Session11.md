# Session report 11: March 05, 2024

**Session objective:** Learn more about PID to improve our closed loop control model, implement trapezoidal speed profiles, make researches about robot trajectories.

## Researches about PID
Previously i had issues with finding the optimum PID coefficients, so i took time to do more researches and i learned many things. All the articles which have led me to this conclusions will be linked in the cources section at the end of the document.

- First of all, if my motors don't have enough power in the end to reach the final position it's cause the integral coefficient is not big enough. Indeed when the error becomes too small, the proportionnal corrector can almost no longer correct it cause it will be the multiplication of a number tending towards 0 by Kp. Then the only way to correct this is catching up with an integral which will see its effect be strongly increased in steady-state.

- I learned the importance of choosing the best sampling frequency. Sampling frequency is used to work with a constant intervall of time used to takes measurements from the encoders and apply correction with a PID.
We would be tempted to put a very high frequency or even using a continous model rather than discret to increase precision but this is a big mistake. Indeed, by increasing this number, we will apply correction more often but on less precise measures as our encoder measured steps at sampling frequency will be inferior for a same distance.
On the other hand, if sampling frequency is to low, our correction will be applied not enough regularly and then we will our command will be jerky

## Trajectory planning
There are multiples itineraries to send the robot from a point to another, so i made researches to identify which one would be the best in our case.

### 1. Circular Arcs:
The robot follows arcs of circles and straight lines to create a continuous trajectory.
Mathematically simple but has C1 discontinuities, leading to acceleration issues.
Risks associated with centrifugal force during high-speed arc changes.

### 2. Bezier Curves:
Aesthetically pleasing and continuous (C1).
Mathematical complexity makes path planning challenging.
Dismissed due to mathematical difficulties.

### 3. Clothoids:
A clothoid is a mathematical curve characterized by a linear increase in curvature, forming a spiral-like shape. It is commonly used in trajectory planning for its smooth and continuous curvature changes, making it mechanically advantageous, particularly in applications like road design and robotics. We would avoid acceleration discontinuities. But it's really a lot of mathematical.
Mechanically practical, despite the need for some approximations.
A succession of clothoid arcs is chosen as the curved trajectory for the robot.

<img src="Report's images\Session11\clothoid.png" width="250">

### 4. Rotation followed by a translation
Finally, after watching some videos from the past years, i noticed that most teams avoid curves trajectories (due to the complexity involved) and choose to work with a succession of a rotation and a translation both independants to reach the wanted point. It may seems not optimum but even the best teams use this method and have excellent results cause they reduce errors on position and centrifuge problems and as distances are shorts the difference in time between this and the previous methods is not considerable.
So I decided to use this method for this year considering the remaining time before the competition (only 2 months).


## Trapezoidal speed command
I spent the end of the session implementing a trapezoidal speed command to avoid wheels spinning at the start of the robot but also at the end to not exceed the setpoint.
I explored many algorithms before choosing to find the most accurate and easy to implement, i learned from the experience of the Cubot Team which have shared their experience on their github.

## **Next session tasks:**
In the upcoming session, i will finish the odometry of the robot and implement trajectories to send him to coordinates on the table with the correct trapezoidal speed profile.

## Sources :
https://github.com/VRAC-team/la-maxi-liste-ressources-eurobot/blob/master/asservissement/Cubot-atelier_asservissement.pdf

https://github.com/VRAC-team/la-maxi-liste-ressources-eurobot/blob/master/asservissement/TechTheTroll-trajectoire_courbe.pdf

https://github.com/VRAC-team/la-maxi-liste-ressources-eurobot/blob/master/asservissement/totofweb-PID_r%C3%A9gulation_de_position_vitesse.pdf
# Session report 12: March 12, 2024

**Session objective:** Develop equations to implement a trapezoidal speed profile for our robot and determine the absolute position of the robot.

# Trapezoidal speed profile

To achieve smooth acceleration and braking, thus preventing slippage, we can implement speed control using a trapezoidal speed profile characterized by three phases: acceleration, constant speed when the maximum authorized speed is reached, and deceleration. I have modeled the profile on GeoGebra to gain a better understanding of the required actions.

[My geogebra modelisation : https://www.geogebra.org/m/n7wgewmr](https://www.geogebra.org/m/n7wgewmr)


<img src="Report's images\Session12\trapezoidal_speed_profile.png" width="800">

Firstly, we can calculate the duration of the acceleration phase and the deceleration phase using our data.

$$ accelerationTime = maxSpeed / maxAcceleration $$
$$ decelerationTime = maxSpeed / maxDeceleration $$

Now, we can deduce the distance traveled during these durations using the kinematic equation for uniformly accelerated motion, which is: 

$$Displacement = InitialPosition+ \frac{1}{2} ​* Acceleration * t^{2}$$

Thus :
$$accelerationDistance = \frac{1}{2} \cdot \text{maxAcceleration} \cdot \text{accelerationTime}^{2}$$
$$decelerationDistance = \frac{1}{2} \cdot \text{maxDeceleration} \cdot \text{decelerationTime}^{2}$$

If $(accelerationDistance + decelerationDistance) < \text{commandDistance}$,  we can apply this profile; otherwise, we won't have enough time to execute the constant speed phase and will proceed with a triangular speed profile.

Finally, we can calculate the distance to be covered during the constant speed phase:
$$ constantspeedDistance = commandDistance - accelerationDistance - decelerationDistance $$ 
Therefore :
$$ constantspeedTime = constantspeedDistance / maxSpeed $$

We are now almost ready to implement this profile in our robot. However, there are additional steps required to reduce rounding errors, but we will address those in the next session.

# Triangle speed profile
Sometimes, the distance command may not be large enough to accommodate the entire trapezoidal speed profile, as we might not have sufficient time to reach the maximum speed. In such cases, we will need to forego the constant speed phase and proceed directly to the acceleration and deceleration phases, resulting in a triangular speed profile.

The main challenge in implementing this triangular profile is that, unlike before, we do not know the maximum speed we will be able to reach. Therefore, I had to find a formula to determine the deceleration duration of this triangular speed profile, considering only the maximum acceleration and deceleration and the distance to be traveled.

To better understand the problem, I modeled it in GeoGebra, so you can visualize it below, where $\tau$ represents the deceleration time we are searching for:

[My geogebra modelisation : https://www.geogebra.org/m/q3h9c6sb](https://www.geogebra.org/m/q3h9c6sb)

<img src="Report's images\Session12\triangle_speed_profile.png" width="800">

We define the following variables : 

Known variables : 
- $a_1$ : maximum acceleration of the robot,
- $a_2$ : maximum deceleration of the robot (negative value),
- $v_2$ : robot's speed at the end of the deceleration phase (= 0 cause at the end of deceleration the robot shouldn't be moving),
- $d_2$ : total distance command.

Unknown variables : 
- $v_1$ : robot's speed at the end of the acceleration phase,
- $t_1$ : time to complete the acceleration phase,
- $t_2$ : time to complete the whole speed profile,
- $d_1$ : distance to perform acceleration phase.

Then we can formulate the following equations from the problem:

$$
\begin{cases}  
v_1 = a_1 \cdot t_1 \\ 
v_2 = a_2 \cdot (t_2 - t_1) + v_1 = 0 \\ 
d_1 = \frac{1}{2} \cdot a_1 \cdot t_1^{2} \\ 
d_2 - d_1 = \frac{1}{2} \cdot a_2 \cdot (t_2 - t_1)^{2} + v_1 \cdot (t_2 - t_1) 
\end{cases}
$$

We have 4 unknown variables and 4 equations, therefore we should be able to solve this system.

For better readability, let's define $\tau = t_2 - t_1 $ as the unknown we are searching for.

$$\Leftrightarrow \begin{cases} v_1 = a_1 \cdot t_1 \\ v_2 = a_2 \cdot \tau + v_1 = 0\\ d_1 = \frac{1}{2} \cdot a_1 \cdot t_1^{2} \\ d_2 - d_1 = \frac{1}{2} \cdot a_2 \cdot \tau^{2} + v_1 \cdot \tau \end{cases}$$


Now let's solve this system : 

$$ l_2, l_3 \rightarrow l_4 \implies d_2 - \frac{1}{2} * a_1 * t_1^{2} = \frac{1}{2} * a_2 * \tau^{2} + (-a_2 * \tau) * \tau $$

$$ \Leftrightarrow d_2 = -\frac{a_2}{2} * \tau^{2} + \frac{a_1}{2} * t_1^{2} $$

$$ l_1, l_2 \implies a_1 * t_1 = v_1 = -a_2 * \tau $$

$$ \implies d_2 = -\frac{a_2}{2} * \tau^{2} - \frac{a_2}{2} * \tau * t_1  $$

$$ \Leftrightarrow d_2 = -\frac{a_2}{2} * (\tau^{2} + \tau * t_1)  $$

$$
\Leftrightarrow \begin{cases} 
(a_1 + a_2) \cdot \tau - a_1 \cdot t_2 = 0 \\ 
\frac{a_2}{2} \cdot t_2 = d_2 
\end{cases}
$$


$$
\Leftrightarrow \begin{cases} 
t_2 = \frac{a_1 + a_2}{a_1} \cdot \tau \\ 
\frac{a_2}{2} \cdot \tau \cdot t_2 = d_2 
\end{cases}
$$

$$ l_1 \rightarrow l_2 \implies d_2 = \frac{a_2}{2*a_1} * (a_1 + a_2) * \tau^{2} $$

$$\tau = \sqrt{ \frac{2d_2a_1}{a_2(a_1+a_2)} }$$

If necessary, we can also determine the maximum speed $v_1$​ now.

$$ v_1 = a_2 * \tau $$

Important note: In our calculus, we considered $a_2$ as a negative value.

# Determining the absolute position of the robot
I have also incorporated basic calculus into my code to track the absolute position of the robot. Each time I sample my measurements, I calculate the distance traveled in centimeters and the angle traveled in radians during this short period. I then update three variables, X, Y, and Z, with basic trigonometry relations to represent the position. Here's how it works:

$$ Z_{position} = Z_{previousposition} + angle_{travelled} $$
$$ X_{position} = X_{previousposition} + (distance_{travelled} * cos(Z_{position})) $$
$$ Y_{position} = X_{previousposition} + (distance_{travelled} * sin(Z_{position})) $$

And $ Z_{position} $ will always be reduced to a value between $-2*\pi$ and $2*\pi$ 

Thus, I am able to obtain the absolute position of the robot on the table in real-time, regardless of its trajectory.

## Special thanks
I would like to thank Mr. Florian Sylvestre, a former Eurobot participant, who took the time to explain in detail how to combine speed profiles and PID, and my mechanical teacher, Mr. Franck Pluvinage, who helped me with kinematic theory.

## Next session tasks
Implement these speed profile equations into my algorithm and estimate the virtual position of the robot resulting from a command sent. Compare it with the real position obtained and correct any errors using PID.
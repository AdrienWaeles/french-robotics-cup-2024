# Session report 5:

**Session objective:** Test the rolling base with belts assembled, finish assembling the coding wheels and test them.


## Belts not stroung enough

First of all, after Loic finished assembling the belts transmissions, we tried the rolling base on the ground. But one belt directly broke due to the starting torque of our motors, so we deduced that sewing the belts may be risky in such competition. 
So to fix this weakness, we found some belts with the wanted length that are already a close loop so we wouldn't have to sew them.

## Assembling the coding wheels

Then, after i finished placing the encoders magnets in their 3d printed support, each one assembled one coding wheel. 

The assembly is mounted on an aluminium shaft cut to the desired size. It includes the wheel, an arm and the 3d printed part that holds the magnet, and washers between them all assembled by force with no tolerances. The encoder is mounted on the arm with the initial spacers and screws. 

<img src="Report's images\Session06\Coding_wheel_without_encoder.jpg" width="250">

Then the other part of the arm is mounted on a 3d printed part on the rolling base with a bolt and washers. 

<img src="Report's images\Session06\Coding_wheel_assembled_rollingbase.jpg" width="250">


## Testing the encoders

I used the code i wrote previously to the encoders on the coding wheels. I came to a really good result for the left wheel but the encoder of the right wheel was continously detecting a variation in the magnetic field so the distance travelled by this one was increasing even when the wheel wasn't spinning.
First i thought it was due to a bad fixation of the encoder so it was moving due to vibrations, but even after fixing it correctly the result was the same. I came to the conlusion that it was due to the magnet we broke that was now made from three parts.

After some researches, I discovered that when a magnet is broken in 3 parts, it will creates 3 distinct fields and we will never have the same field.

<img src="Report's images\Session06\tested_magnet.jpg" width="100">
<img src="Report's images\Session06\original_magnet.jpg" width="88">


I tried to replace this magnet with a neodym magnet i found but the result was really strange. On one side of the magnet, the encoder was detecting no variation and on the other side the encoder was detecting a huge variation. As our magnet had a hole in the center, i asked myself if this had an influence on the magnetic field, so to verify that i tried to drill a hole in the new magnet with a drill press but it was really hard to maintain it perpendicular to the drill without creating an adapted support.

To understand better the problem i had to understand how an encoder works precisely. A magnetic encoder detects rotational position information as changes of the magnetic field. When the permanent magnet attached to the motor shaft rotates, the direction of the magnetic field detected by the magnetic sensor changes, as a result the encoder detects the rotational position and speed of the motor shaft.

I found that there are different type of magnets.
<img src="Report's images\Session06\magnetization_field_lines_fromAKM.png" width="450">

As i didn't found any documentation containing the characteristics of the encoder's magnet, i decided to call the seller to ask them some information about it. And they agreed to sell a new one independently.

## **Next session tasks:**
After we will receive the new magnet and the appropriate belts, our rolling base should be finished so i will try to test it, make some ameliorations if necessary and start finding the PID coefficients.

## Sources 
https://www.akm.com/eu/en/products/rotation-angle-sensor/tutorial/magnetic-encoder/
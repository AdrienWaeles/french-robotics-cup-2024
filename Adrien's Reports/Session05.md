# Session report 5:

**Session objective:** Assemble the pivots joints of the coding wheels and position the encoders in front of the coding wheels axis.


## Recovering spacers and magnets initially present at the end of the motor shaft

First of all, i dismantled the encoders to reposition them in front of the coding wheels to fit with our new design. Firstly, i recovered the encoders spacers which will be reused to fix the encoders in front of the coding wheels axis. 

<img src="Report's images\Session05\encoder_spacers.jpg" width="300">

Then i dismantled the magnets from the end of the two motors shafts (circled in the photo) cause we will need them in front of the new positions of our magnetic encoders.
<img src="Report's images\Session05\magnet_motorshaft.jpg" width="300">

This was very hard cause the magnets were probably hot-assembled. As i needed more strenght to remove it, i tried using the pliers as a lever but it didn't worked. So i finally used a vise to hold firmly the motor by its lower shaft to avoid tearing off the motor shaft and another pair of pliers to stop it turning on itself. After a long time and some help, i finally reached recovering the magnets even if one broked in the process.

<img src="Report's images\Session05\recovering_magnet.jpg" width="300">

## Modeling and 3d printing a part to assemble magnets and metalrods together

We needed to position the magnets we recovered at the end of our coding wheels metalrods. 
As gluing them together didn't seemed like the best solution due to the rotational speed of coding wheels and cause loosing the magnets during the competition would be dramatic as we wouldn't be able to correct our trajectories anymore and we would loose track of the robot localization, i decided to create a little 3d printed part that will be used as a flush-link connection.

<img src="Report's images\Session05\3djoint_magnetmetalrod_1.png" width="200">
<img src="Report's images\Session05\3djoint_magnetmetalrod_2.png" width="200">

Each part is inserted by force into a hole in the plastic part with no tolerance and to reinforce the fixation we even added glue on the plastic part.

<img src="Report's images\Session05\metalrod&magnet_assembled.jpg" width="400">

## Cutting an aluminium rod to use them as axis for the coding wheels

Finally i cutted the rod in two parts of 15mm with a hacksaw so their lenght will be perfectly adapted to fit with the coding wheel pivot join. 
<img src="Report's images\Session05\cutting_metalrod.jpg" width="200">
I also smoothed the cutted surfaces with a metal file.

## **Next session tasks:**

Next session, i will finish assembling the coding wheel fixation modelled by Loic and if our rolling base is ready to move, i will test our algorithm to start implementing determinning our PID coefficients.
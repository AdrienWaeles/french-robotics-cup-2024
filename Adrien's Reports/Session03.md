# Session report 3:

**Session objective:** : 
- Assemble the solar panels (game accessories) to prepare for the manufacturing of the playfield.
- Create the closed loop motors control algorithm

## Assembly of the 9 solar panels

The playfield of the competition is composed of 9 elements called "solar panels". 
These elements are disposed on one border of the table. They have 2 colors, robots will have to rotate as many solar panels as possible to put their color toward the inside of the table and mark points. Each one is made with two 3D parts, a cut of vinyl, one screw, a nylstop nut and a washer.
So first, i sliced the 3d parts after entering the specified parameters by the rules. Indeed to be approved by the rules, our models must have similar weight and dimensions so we will be able to reproduce the competition conditions with precision. 

<img src="Report's images\Session03\2solarpanels_slicing.png" width="400">

That's why, i needed notably to modify the fill density to 40% and the fill pattern to "Cubic".

<img src="Report's images\Session03\slicing_parameters.png" width="300">

Then to assemble the two 3d printed parts i used a CHC M6*50mm screw with a Nylstol Nut and between the two parts a washer do diminue friction following instructions plan :

<img src="Report's images\Session03\assembly_solarpanels_screw&nuts.jpg" width="300">
<img src="Report's images\Session03\assembly_instructions.png" width="300">

The main difficulty was that the nut was spinning in the void when i screwed the assembly. So i had to jam a flathead screwdrive between the plastic part and the nut when screwing.

Then i cutted our vinyl with a cutter to dettach the solar panels shapes and glue them onto the 3d part (respecting the good orientation).

<img src="Report's images\Session03\vinyl_carpet_accessories.jpg" width="300">

Here are all the 9 solar panels ready to be fixed on the table :

<img src="Report's images\Session03\9solarpanels_assembled.jpg" width="300">

## Programming the closed loop control


## **Next session tasks:** 
- Test the closed loop control algorithm on the robot and choose relevant coefficients
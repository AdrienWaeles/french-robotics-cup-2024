# Session report 4:

**Session objective:** Test the algorithm i wrote during the previous session, fix bugs and implements new functionnalities

## Issue with serial speedrate

First of all, i had a big issue with the speed of execution of the code. The algorithm was slow down due to the speed of communication which was only 9600 bits per second. The arduino was not capable of maintening the motors pins to high while printing the number of ticks of the encoder on the serial connection due to this speed rate. I simply had to initialize this value to 115200 bits in the Serial.begin().

## Receiving commands from the monitor
Then i implemented a function which allows us to send command to the robots from the monitor using serial communication.

Each time a character is available in the buffer, we read it and add it to the first empty position in the list (thanks to the indice position_character increasing at the same time).
When this character is a line break, we call a function which will parse the command.


<img src="Report's images\Session04\code_buffer_serial_connection.png" width="600">

# Parsing the command to get input parameters

To parse the command we compare the first characters with the possible expected results. 
Thus, if the first character are "d=" we expect that the next characters converted to an int will be the distance_command. As well as "r=" to indicate that the next characters will be an angle value.

<img src="Report's images\Session04\code_readCommand.png" width="600">

<img src="Report's images\Session04\code_correctDistance.png" width="600">


## **Next session tasks:**

Before the next session, we should have finished assembling the new rolling base so i will be able to implement my algorithm on the robot and calculate PID coefficients

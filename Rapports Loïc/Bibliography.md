
<span style="font-family: 'cmunrm';">

# Bibliography: Robot competing in the Coupe de France de Robotique
## The PolyMartian
### Table of contents :
1. [Introduction](#Introduction)
2. [Goal](#Goal)
3. [Rules analysis](#Rules-analysis)
4. [Technical specifications](#Technical-specifications)
5. [Strategy](#Strategy)
6. [Equipment list](#Equipment-list)
7. [Main robot’s conception](#Main-robot’s-conception)
    1. [Rolling base](#Rolling-base)
    2. [Grasping actuator](#Grasping-actuator)
    3. [Storage](#Storage)
    4. [Sensors](#Sensors)
    5. [Power supply](#Power-supply)
8. [Algorithm](#Algorithm)
9. [Gantt diagram](#Gantt-diagram)
10. [Work distribution](#Work-distribution)
11. [Sources](#Sources)

### Introduction :
The “Coupe de France de Robotique” is a competition involving the creation of an
autonomous robot based on a specific theme that has to carry out a certain number of
actions over a specific period of time, simultaneously with rival robots. It is the biggest
gathering of engineering schools in France, giving three teams access to the European
Eurobot competition.
The main goal of this project is to gather students around a huge project to .. and learn from
each other. while representing our school, Polytech Nice Sophia, and raising awareness of
its Robotics and Autonomous Systems speciality.
Rules analysis :
Year's theme: in order to make life on Mars possible, the robots are tasked with running an
autonomous greenhouse so astronauts will be able to harvest fruits and vegetables, and
then survive. To do this, robots will perform on a table of 3m per 2m and accomplish different
missions.
At the start of the game, each team is assigned a color : yellow or blue. The team will have
to place its robot in one of the three square surfaces on the extremity of the playfield
delimited by its color line (areas number 1 or 2 on Figure 2). Then each robot will have 100
seconds to mark as many points as possible without any human intervention. To mark
points, robots can realize some of the following actions :
- Repot the plants and put them in cultivation,
Thirty-six plastic plants are arranged by groups of six on the playfield (areas 5 on Figure 2).
Each group is made of two types of plants : four fragiles with white pots and two resistants
with purple pots (Figure 6). The team will earn points for each plant dropped off upright in a
valid area.
Each plant has a diameter of 5cm, a height of 12cm and a maximal weight of 25g.
There are three different dropping areas :
- standard drop-off areas (areas number 1 on Figure 2) where plants can be stolen by
the other team;
- reserved drop-off areas (areas number 2 on Figure 2) that are protected from theft;
- Planters which are outside and separated from the playfield by a border (areas
number 7 on Figure 2).
While resistant plants can be dropped off in any dropping area, fragile ones can only be
dropped off in planters.
Furthermore, to mark additional points the robot can drop off the plant in a metallic pot.
Indeed thirty-six steel pots are placed by groups of six around the table (areas 4 on Figure 2)
including two stacked one on top of the other.
Each steel pot has a diameter of 7cm, a height of 6.5cm and a maximal weight of 50g.
There are also some constraints :
- For each deposit area, no more than six plants will be counted.
- A plant still under control by a robot at the end of the match won’t be counted.
- Stealing a plant from the opponent protected deposit area will result in a forfeit
- Orient the solar panels so that the greenhouse does not lose energy:
The greenhouse is also made up of nine solar panels (components 8 and 9 on Figure 2).
Among them, each team has 2 reserved solar panels on the table's extremities which cannot
be manipulated by the opponent's robot (components 9).
A solar panel is a 3d printed square component which rotates on an axis. Each solar panel
has two sides, one yellow and the other one blue (Figure 8). At the beginning of the match,
they are all oriented towards the outside of the table.
To mark points the robot has to manage to turn the solar panel in order to put a part of the
vertical projection of the edge with the team color inside the table. If both color edges are
inside the table, both teams gain the points.
- Ensure the pollination of plants,
To ensure pollination of plants each team must create Small Independent Mobile Actuators
(SIMA) also called ladybugs. These SIMA will start the game from the ladybug hive (areas
number 3 on Figure ??). A team can have as many ladybugs as they want as long as they all
fit in their starting zone.
They can only be released between the 90th and 100th seconds of the match and will have
10 seconds to accomplish their goal.
A team wins points for each plants’ deposit area occupied by at least one ladybug at the end
of the match. Extra points are granted for each plants’ deposit area where at least one
ladybug is in contact with a plant or pot containing a plant.
However, if one ladybug is in an opponent’s area, it will score points for the opposing team.
- Return to recharge the batteries, at the end of the working day,
The team will also score points if the robot is in an arrival area, which has to be different
from its departure area, before the end of the match.
- Anticipate future crop yield.
Finally the robot can estimate its score (excluding the score produced by ladybugs), either at
the beginning of the match on a static display or during the match with a dynamic display. A
bonus, proportional to the difference between the score estimated and the real performance
will be granted.
Robot specifications:
- Move forwards and backwards with a precision of less than 1 cm and turn around very
quickly
- To be able to pick up plants, place them in pots and take them to the various storage areas
- Identify the type of plant (fragile or resistant)
- Point the solar panels in the right direction
- Comply with the robot's design constraints:
Perimeter (vertical projection on the ground) less than 1200 mm at the start. The deployed
perimeter must be less than 1300 mm during the match.
Total height less than 350mm (375mm with emergency stop button) excluding the beacon
support mast.
- Must include a start-up cord for autonomous robots
- Avoidance system for opposing robots to prevent collisions between robots during a match.
- Safety conditions: All robots must be equipped with a red emergency stop button at least
20 mm in diameter
- Return to its base before the end of the 100-second match.
- Estimate the score produced
- Include a beacon mast ???
- All ladybugs must enter inside the SIMA starting area (15 cm by 45 cm), have a height limit
of 15 cm and must be larger than a 60mm cube and each ladybug’s weight must not
exceed 1kg.
Gantt’s diagram and repartition
Choice of base type (shape, wheel type) :
Motor selection and sizing :
The best teams often use very expensive engines because of their
performance/compactness ratio. If the above-mentioned engines are not sufficient, we plan
to acquire Maxon engines with the following configuration.
Advantages/Disadvantages
### Estimation du poids :
### Choix du système de stockage : pour éviter des aller retour
### Solutions envisagées : empiler les pots, tapis roulants,
### Choix du type de saisie d’objets :
### dentifier le type de plantes
### Choix de la matière de la base roulante
### Choix du système de vision
## Technical description :
### The rolling base / chassis :
The rolling base or chassis is composed of two main plywood plates (~5mm thickness)
assembled together with 3D printed spacers. This configuration offers multiple advantages
over a single thicker plywood plate. The first advantage is the possibility to store the
batteries, the electronics and the motors into a safe volume between the two plates and still
be able to set elements above all these components. In this case, plywood offers a great
rigidity but remains lightweight so the robot is solid and easy to accelerate at the same time.
Moreover, plywood is an affordable material compared to aluminum and is very easy to
process with a laser cutter and usual woodworking tools. Also, plywood lets us make quick
modifications on the parts which is very useful for prototyping.
The 3D printed parts are designed to keep a constant spacing between the plywood plates.
They are held in place by screws which pass through the plates and the 3D-printed parts
and are screwed into the robot's upper structure (Figure 1).
Figure 1
Some of the spacers also have the role to maintain the motors in place.
The motors are screwed onto these parts on the side closest to the wheels (Figure 2).
Figure 2
The other components are directly screwed onto the plywood plates except the batteries
which need to be easily and quickly removed from the robot for their replacement and
recharge.
Finally, the base is enclosed from every side with smaller plywood plates in order to protect
the components inside from dust and chocks (Figure 2).
The wheels are modified rollerblade wheels so we can apply torque to them and mount them
directly on the motors’ shafts.
### The upper structure :
The upper structure (Figure 3) is the continuity of the rolling base. It supports cameras and
other sensors (IR, lidar), as well as the emergency stop button on top of the robot. This
structure is made out of standard v-slot 20x20mm aluminum profile sourced on the website
www.systeal.com so they came already at the right size and with the threaded ends. This
type of profile allows us to easily fix components on them and offers a great rigidity for a
minimum weight. Like the base, the upper structure is closed from all sides except the front
one so the grabbing system can freely manipulate the pots and the plants. Like the rolling
base, we use plywood panels screwed onto the aluminum profiles (hidden on figure 3) to
close the robot’s sides.
Figure 3
### The storage system :
In order to be as competitive as possible, the robot has to temporarily store the pots and
plants it found on the field so it minimizes the number of deplacement which are time
consuming. The storage system (Figure 4) is composed of two main elements : a stepper
motor and a laser cutted plywood plate. The latter is directly mounted on the stepper motor
shaft. In this system, a stepper motor was chosen for its rotational speed and ease of use in
positioning the turntable. The motor is held in place with a 3D printed part screwed onto the
plywood panel under it. The turntable has the shape of a disc with six 70mm holes around it.
The layout of this part is optimized to store cone geometry like the plant pot, so when the
gripping system releases a pot above the turntable, the pot naturally centers and straightens
out with gravity. This technique makes the system very simple and repetitive in its task with
no use of electronics.
Figure 4
Before opting for this solution, we considered storing the pots and plants on conveyors, but
this solution was not chosen because of the problem of potting the plants. A conveyor
doesn't have as much stability and repeatability as a turntable, as it can't prevent the
movement of pots and plants while the robot is moving. What's more, a conveyor is a more
complex system, requiring more moving parts to operate.
### The gripping system :
To respond to its tasks, the robot will have to manipulate
## Sources :
https://www.coupederobotique.fr/edition-2024/le-concours/reglement-2024/

</span>
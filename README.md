Engineering materials
====
- 3d printed chasis (C:\Users\samue\OneDrive\Documents\Outcasts\models\Models\Placa Base Robot V4.stl)
- Arduino Mega 2560 
- 2 protoboards 
- Motor driver L298N
- 2 9v battery 
- 2 Ultrasonic sensors 
- 2 dc motors with gears 
- lots of cables and duck tape ;)

the world is our canvas. The future is ours.

## Project

We will explain briefly how we developed kratos and why we made the engineering desicions that lead to this prototype. This section will only cover the latest version of the robot.

- Mobility Management

We used 2 standard dc motors both managed by the L298n motor driver. this driver is conected to the Arduino mega digital ports and to an external standard 9v battery. The driver allows us to chose the speed and orientation of the dc motors, these may move foward or in opposite directions when the car is turning. these are attached to the back of the chassis and under the main piece. 

For steering we used a standard size servo mg996r located at the front of the chasis connected to the 3d printed steering structure (C:\Users\samue\OneDrive\Documents\Outcasts\models\Models\Acople para rueda y rodamiento.STL) the servo's signal cable is connected to the 40th pin of the board and moves from 60 degrees all the way up to 120 degrees.

The chassis is composed of 3 pieces: the base (C:\Users\samue\OneDrive\Documents\Outcasts\models\Models\Placa Base Robot V4.stl) and the steering mechanism (C:\Users\samue\OneDrive\Documents\Outcasts\models\Models\Acople para rueda y rodamiento.STL).

- Power and Sense Management

To power Kratos we are using 2 9v batteries, one is connected directly to the motor drive and the other is connected to the mega at it's vin and GND ports. These are rechargable and can store up to 600 mAh. To sense it's eviroment we included 2 ulstrasonic sensors one at each side, these are connected to the 53, 51, 24, 22 pins of the mega and detect whether or not there's a wall to it's side, if the aswer is negative it'll turn making sure it's always on the right path. 

Full length programs are stored here (C:\Users\samue\OneDrive\Documents\Outcasts\src\Full) other programs or testing code is stored here (C:\Users\samue\OneDrive\Documents\Outcasts\src).

- Obstacle Management

For v0.3 we used 2 ulstrasonic sensors to ensure it would follow the path of the track and avoid the walls. we will not have full obstacle evasion until the camera is installed which we plan to do before v0.4, we will implement the pixy 2.1 and have it analize the blocks in front of it to avoid them acordingly (this is not finished as of 5/14/24).

## Logs

v0.1: For this first prototype we designed a simple robot that simply circles the track in patter like way for 3 loops. We did not implement any sensors on the first version due to the instability that these had prior to the first competition. We used a motor drive to move the car forth, this motor is located under the chasis. We used a standard servo to steer the car with a 3d printed steering structure.


v0.2: This time arround we implemented ultrasonic sensors to ensure the robot turns the edges correctly, we used a simple condition that checks wether or not there's a wall to the side of the sensor, if the output is negative the robot will turn. The robot is too fast and the sensors have trouble recongnizing walls. 

v0.3: We polished the sensors and installed a new support for them. we also used the ENA & ENB ports of the motor driver to contro the speed and increase the sensors precision.
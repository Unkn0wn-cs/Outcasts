Engineering materials
====
- 3d printed chasis 
- Arduino Mega 2560 
- 2 protoboards 
- Motor driver L298N
- 2 9v battery 
- 2 Ultrasonic sensors 
- 2 dc motors with gears 
- lots of cables and duck tape 

the world is our canvas. The future is ours.
## Content

* `t-photos` contains 2 photos of the team (an official one and one funny photo with all team members)
* `v-photos` contains 6 photos of the vehicle (from every side, from top and bottom)
* `video` contains the video.md file with the link to a video where driving demonstration exists
* `schemes` contains one or several schematic diagrams in form of JPEG, PNG or PDF of the electromechanical components illustrating all the elements (electronic components and motors) used in the vehicle and how they connect to each other.
* `src` contains code of control software for all components which were programmed to participate in the competition
* `models` is for the files for models used by 3D printers, laser cutting machines and CNC machines to produce the vehicle elements. If there is nothing to add to this location, the directory can be removed.
* `other` is for other files which can be used to understand how to prepare the vehicle for the competition. It may include documentation how to connect to a SBC/SBM and upload files there, datasets, hardware specifications, communication protocols descriptions etc. If there is nothing to add to this location, the directory can be removed.

## Introduction

v0.1: For this first prototype we designed a simple robot that simply circles the track in patter like way for 3 loops. We did not implement any sensors on the first version due to the instability that these had prior to the first competition. We used a motor drive to move the car forth, this motor is located under the chasis. We used a standard servo to steer the car with a 3d printed steering structure.


v0.2: This time arround we implemented ultrasonic sensors to ensure the robot turns the edges correctly, we used a simple condition that checks wether or not there's a wall to the side of the sensor, if the output is negative the robot will turn. The robot is too fast and the sensors have trouble recongnizing walls. 
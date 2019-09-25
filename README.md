# Spherical_treadmill

Mouse sensors and Arduinos to get the yaw-pitch-roll of an air-floating ball.
The ball and its holder (JetBall) are made by the company Phenosys. 
They also provide sensors that work similarly (mouse sensor + Arduino Micro) but are more limited since they can only interface via USB, using 2 ports on the machine and making local computations difficult.
Since our setups involve 1 PC for multiple rigs, it is easier to have one Arduino Due per setup and delegate computations.
(Also, the company sells the sensors ~2600€ a pair, and the parts to make the full system from scratch cost ~100€ top.)

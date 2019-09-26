# Spherical_treadmill

Mouse sensors and Arduinos to get the yaw-pitch-roll of an air-floating ball.

## Motivation

The ball and its holder (JetBall) are made by the company Phenosys. 

They also provide sensors that work similarly (mouse sensor + Arduino Micro) but are more limited (and compact, there is no Due) since they can only interface via USB, using 2 ports on the machine and requiring computations to take place on the PC.

Since our setups sometimes involve 1 PC for multiple rigs, it is easier to have one Arduino Due per setup and delegate computations.

Also, some of our original sensors broke: the company sells the sensors ~2600€ a pair, and the parts to make the full system from scratch cost ~100€ top.

## Setup

Two PMW3360 high-end gaming mouse sensors are used to track the XY displacement of a polystyrene ball (see picture). 

You can buy them here for 30$: https://www.tindie.com/products/jkicklighter/pmw3360-motion-sensor/

Those sensors are connected to Arduino Micro's (which you can buy in a variety of places for 20$). 

The full code for them  is available here: https://github.com/SunjunKim/PMW3360_Arduino

I use the PWM3360DM-Burst script, which is included in this repo.

Those Micro's are sending XY displacement to an Arduino Due, which computes the yaw-pitch-roll displacements of the ball.

From there other informations can be computed, like speed.

![picture](spherical_treadmill.jpg = 200x)
![picture](https://github.com/aphilip442/Spherical_treadmill/blob/master/spherical_treadmill.jpg)
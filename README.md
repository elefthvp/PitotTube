# PitotTube
A library, Arduino scripts and intermediate calculation pieces of code for a Pitot Tube used to measure the relative velocity of an Unmanned Air Vehicle. Implemented while working for ASAT Aeronautics Project.
## Main Idea
<p align=justify> A Pitot Tube is a device used to measure flow velocity. The Aeronautics Project uses one to determine airspeed velocity of the aircraft it constucts. </br> </p>

## Hardware 
- a  small Pitot Tube
- an MPXV7002DP differential pressure sensor
- two silicon tubes with a cross-sectional area that fits that of the Pitot Tube
- an Arduino Board and a compatible cable 

## Operation Principle of a Pitot Tube
<p align=justify> The Pitot Tube consists of a tube that points directly into the fluid we desire to measure. We thus measure the stagnation pressure and then subtract the static pressure to calculate the dynamic pressure.</br> </p>
<p align=justify> The dynamic pressure is then used in Bernoulli's equation for flow velocity, taking the rho constant (fluid density) of the atmosphere in the area where the experiments are taking place into consideration. 









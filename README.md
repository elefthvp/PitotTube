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
  
## Operation Principle of the MPXV7002DP sensor 
### Read value
<p align=justify> This sensor can measure differential pressure in the range of -2 to 2 kPa.
It returns a raw value between 0 and 1023. <br></p>
### Negative and Positive Differential Pressure 
<p align=justify> A value of 0 to approximately 510 symbolises a negative differential pressure, while a a value of approximately 514 to 1023 stands for a positive one. 
Actually, the space between 510 and 514 can be considered a dead zone with a dead zone span designer parameter equal to 2 points up (512 to 514) and 2 points down (512-510). The dead zone is used to avoid unwanted fluctuations between maximum (in the absolute value sense) negative differential pressure and minimum positive The span can be considered a designer parameter according to our equipment and the way it behaves. <br></p> 
###  Offset and Reduction of Read Value 
<p align=justify> The read value is always reduced to a 0-512 span by subtracting (1023/2) from it. The sign is saved in a boolean value before the subtraction takes place. <br> </p>
<p align=justify> Everytime we start the experiments for the day, it is wise to measure the offset of the Pitot Tube. After covering it up with a piece of cloth and placing it on a motionless surface, we take certain measurements to determine a possible offset it might be measuring. For example, even though it might not be exposed to air flow, it is possible that it returns a value of 525. This value represents a positive differential pressure although no particular airflow exists (i.e. we're in the lab and the pitot is sitting on the table). Thus, everytime we start the device, it is wise to take a certain amount of measurements, calculate their offset from 512 and then average them for a mean offset that will be used in our actual experiments. <br></p>
<p align=justify>The post-procession raw data is then mapped to ouput voltage according to: 
 <img src="https://latex.codecogs.com/gif.latex?\bg_white&space;Vout&space;=&space;vref*input/512" title="Vout = vref*input/512" />
 Note that vref is the chosen reference voltage of the Arduino Board, usually 3 or 5.
<br></p>
###  Pressure Derivation
The ouput voltage is used as an input to the transfer function given in the datasheet of the sensor. A simplified version of it is:
<img src="https://latex.codecogs.com/gif.latex?\bg_white&space;P=Vout-2.5" title="P=Vout-2.5" /> 
where P is in kPa

### Bernoulli Velocity
Using the formula 
<img src="https://latex.codecogs.com/gif.latex?\bg_white&space;\sqrt{(2*P/rho))}" title="\sqrt{(2*P/rho))}" />
we derive the airspeed in m/s. Mind that the pressure has to be in Pascal, so an intermediate calculation from kPa to Pa happens.








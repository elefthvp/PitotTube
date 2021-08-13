# Pitot Library
<p align=justify> This library is inserted to create and initialize a Pitot object in an Arduino script. Define an object and call the PITOT_update() function in the loop section. 
 
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

## Constructor Default Values
|Design Parameter| Descirption | Default Value | 
|---|---|---|
| sensorPin | The pin where the Analog pin of the MPXV7002DP sensor is connected | 4 |  
| zero_span | The span considered when checking the deadzone | 2 |  
| rho| Air density of the area we're in, needs to be adjusted according to our location | 1.204 | 
---

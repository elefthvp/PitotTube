# Description
Usage example of the implemented Pitot Library. 

# Synopsis
- Create a Pitot Object at the global definitions part of the programme.
- Calibrate it by calling the OffsetCalculation(x) function, where x is the number of desired iterations.
- Call it in the loop by using varname.PITOT_update(). Add a small delay that corresponds to your needs.
- 
# Dependencies 
- Pitot_library.h
- SoftwareSerial.h

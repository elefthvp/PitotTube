#include "Pitot_library.h"
#include <SoftwareSerial.h>

//create a PITOT object 
PITOT pitotTube;

//setup section 
void setup() {
  Serial.begin(9600);
  Serial.println("Sensor Initialization");
  delay(1000);
  
  //initialize it by calculating the offset once. Give number of iterations as an argument considering observed fluctuations.
  pitotTube.offsetCalculation(10);
}

//loop section
void loop() {
  pitotTube.PITOT_update();
  
//wait a little between measurements 
  delay(500)
}

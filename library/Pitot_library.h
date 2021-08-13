#ifndef PITOT_LIBRARY_H
#define PITOT_LIBRARY_H
#pragma once

class PITOT
{
	private:
	
	float measurement;
	int sensorPin;
	float offset;
	float sensorValue;
	int zero_span;
	bool signFlag;
	float Vout;
	float velocity;
	float P;
	float PinPa;
	float rho;
	
	public:
		PITOT();
		void PITOT_update();
		void offsetCalculation(int offset_size);
		bool deadZoneCheck(float sensorValue);
		void setSensorPin(int sensorPin);
		void setZeroSpan(int zero_span);
		bool signCheck();
		void rawToVoutMap();
		void diffPressure();
		void BernoulliVelocity();
		void setRho(float rho);
	
};

PITOT :: PITOT() 
{
	this->measurement=0;
	this->sensorPin=4;
	this->offset=0;
	this->sensorValue=0;
	this->zero_span=2;
	this->signFlag=false;
	this->Vout=0;
	this->velocity=0;
	this->P=0;
	this->PinPa=0;
	this->rho=1.204;
	Serial.println("Hello Avionics, let's fly!");
}

void PITOT :: offsetCalculation(int offset_size){
	Serial.println("Sensor Offset Calculation");
	float sum=0,offset;

	for (int i=0;i<offset_size;i++){
		Serial.print("Offset in iteration: ");
    	Serial.println(i);
		
    	measurement=analogRead(sensorPin)-(1023/2);
  	
		Serial.println(measurement);
    	
		sum = sum+measurement;

    	delay(500); 
	}
	
	offset = sum / offset_size;
	Serial.println("Sensor Offset is equal to");
	Serial.println(offset);
	this->offset=offset;
}

void PITOT ::  PITOT_update(){
	sensorValue = analogRead(sensorPin)-offset;
    	deadZoneCheck(sensorValue);
	signFlag=signCheck();
	rawToVoutMap();
	diffPressure();
	
	

	
	
}

bool PITOT :: deadZoneCheck(float sensorValue){
	Serial.println("sensor value before dead zone check");
	Serial.println(sensorValue);
	delay(1000);
	//if I find myself in a "dead zone", I re-read the analog pin
	//if not, the while loop will be ignored
	while(sensorValue>512-zero_span and sensorValue<512+zero_span){
	sensorValue = analogRead(sensorPin)-offset;	
	Serial.println("I'm in the dead zone check");
	Serial.println("New value after dead zone check: ");
	Serial.println(sensorValue);
	delay(2000);
	}
    
	
}

void PITOT ::  setZeroSpan(int zero_span){
	this->zero_span=zero_span;
}
void PITOT ::  setSensorPin(int sensorPin){
	this->sensorPin=sensorPin;
}
bool PITOT ::  signCheck(){
	static bool positive;
        if (sensorValue > 512){
                positive=true;
                sensorValue=sensorValue-512; 
        }else{
                sensorValue=512-sensorValue;
    }
	return positive;
}

void PITOT :: rawToVoutMap(){
	Vout=5*(sensorValue)/512;
       	Serial.println("Vout is:");
       	Serial.println(Vout);
       	delay(2000);
}
void PITOT :: diffPressure(){
	P=Vout-2.5; 
    	Serial.println("Pressure in kPa is:");
   	Serial.println(P);
    	if(P>0){
      	 	PinPa=P*1000; //in Pa
      	 	Serial.println("Pressure in Pascal");
       		Serial.println(PinPa);
	   	BernoulliVelocity();
	}
}
void PITOT :: BernoulliVelocity(){
	velocity= sqrt(2*PinPa/rho);
	
        if (signFlag==false){
          	velocity=-velocity;
        }
        Serial.println(velocity); // print velocity
       
}
void PITOT :: setRho(float rho){
	this->rho=rho;
}
#endif

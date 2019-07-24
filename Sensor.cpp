#include "Arduino.h"
#include "Sensor.h"

Sensor::Sensor(){
  pin = 0;
  pinMode(pin, INPUT);
}
Sensor::Sensor(int p){
  pinMode(p, INPUT);
  pin = p;
}

float Sensor::retValue(){
  pulse = pulseIn(pin, HIGH);
  cm = pulse * 2.54 / 147;
  return(cm);
}








  

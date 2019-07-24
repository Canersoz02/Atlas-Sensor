
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class Sensor{
  public:
    int pin;
    long pulse;
    float cm;
    Sensor();
    Sensor(int p);
    float retValue();
};
#endif
#include "Arduino.h"
#include "LightSensor.h"
 using namespace std;

LightSensor::LightSensor(int pin_resistance){
  this->pin_resistance=pin_resistance;
}

uint16_t LightSensor::getLight(){
  return  this->pin_resistance;
}

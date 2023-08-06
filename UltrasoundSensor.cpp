#include "Arduino.h"
#include "UltrasoundSensor.h"
using namespace std;

UltraSoundSensor::UltraSoundSensor(int pin_trig, int pin_echo) {
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
 
  digitalWrite(pin_echo, LOW);

  this->pin_trig = pin_trig;
  this->pin_echo = pin_echo;
}

float UltraSoundSensor::getDistance() {
   digitalWrite(this->pin_trig, HIGH);
   delayMicroseconds(10);
   digitalWrite(this->pin_trig, LOW);
 
  long temps = pulseIn(this->pin_echo, HIGH);
  float distance;
  if (temps > 25000) {
    }
  else {
    temps = temps/2;
    distance=(temps*340)/10000.0;
  }
  return distance;
}

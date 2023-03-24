#include "HC-SR04.h"

HCSR::HCSR(unsigned short _trig, unsigned short _echo){ 
  trig = _trig;
  echo = _echo;
  pinMode(trig, OUTPUT);
  pinMode(echo , INPUT);
  digitalWrite(trig, 0);
}

long HCSR::read(){
  long dist, dur;
  
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  dur = pulseIn(echo, 1);
  dist = (dur/2)/29;

  return dist;
}
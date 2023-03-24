#ifndef HCSR04
#define HCSR04

#include <Arduino.h>

class HCSR{
  private:
    unsigned short trig;
    unsigned short echo;
  public:
    HCSR(unsigned short, unsigned short);
    long read();
};

#endif
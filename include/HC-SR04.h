#ifndef HCSR04
#define HCSR04

#include <stdint.h>
#include <Arduino.h>

class HCSR{
  private:
    uint8_t trig;
    uint8_t echo;
  public:
    HCSR(uint8_t, uint8_t);
    uint8_t read();
};

#endif
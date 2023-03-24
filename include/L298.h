#ifndef L298
#define L298

#include <stdint.h>
#include <Arduino.h>

class L298N{
  private:
    unsigned short IN1;
    unsigned short IN2;
    unsigned short IN3;
    unsigned short IN4;
    unsigned short ENA;
    unsigned short ENB;

  public:
    L298N(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
    void power(uint8_t);
    void forward();
    void back();
    void left();
    void right();
};

#endif

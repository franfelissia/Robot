#ifndef L298
#define L298

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
    L298N(unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);
    void power(unsigned);
    void forward();
    void back();
    void left();
    void right();
};

#endif

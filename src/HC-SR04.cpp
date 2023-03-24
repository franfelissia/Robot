/*
  Esta libreria está hecha para controlar el módulo HC-SR04 para poder
  implementarlo en un robot.
*/

#include "HC-SR04.h"

HCSR::HCSR(uint8_t _trig, uint8_t _echo){ 
  /*
    Acá declaro en que entradas estan conectados los pines del módulo y
    les doy un valor de inicio.
  */
  trig = _trig;
  echo = _echo;
  pinMode(trig, OUTPUT);
  pinMode(echo , INPUT);
  digitalWrite(trig, 0);
}

uint8_t HCSR::read(){
  /*
    Con este metodo mando la señal por el pin de trig que empiece la medición,
    resivo el dato por el pin de echo, lo convierto a centimetros y lo devuelvo.
  */
  long dur;
  uint8_t dist;
  
  digitalWrite(trig, 1);
  delayMicroseconds(10);
  digitalWrite(trig, 0);

  dur = pulseIn(echo, 1);
  dist = (dur/2)/29;

  return dist;
}
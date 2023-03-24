/*
  Esta librería permite utilizar el chip L298N para controlar dos motores de corriente continua
  para el manejo del robot.
*/

#include "L298.h"

L298N::L298N(uint8_t _IN1, uint8_t _IN2, uint8_t _IN3, uint8_t _IN4, uint8_t _ENA, uint8_t _ENB){
  IN1 = _IN1;
  IN2 = _IN2;
  IN3 = _IN3;
  IN4 = _IN4;
  ENA = _ENA;
  ENB = _ENB;
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void L298N::power(uint8_t vel){
  /*
    Con este método aplico una señal de pwm soble los pines de habilitación de los motores.
    Ésto permite encender y apagar los motores teniendo un control sobre la velocidad que alcanzan.
    
    Podria mejorarce conciderando cada motor por separado y con sensores opticos para poder ir
    ajustando el valor del pwm.
  */
  
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

void L298N::forward (){
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void L298N::back (){
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void L298N::left (){
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void L298N::right (){
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}
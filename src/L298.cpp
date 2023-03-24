#include "L298.h"

L298N::L298N(unsigned short _IN1, unsigned short _IN2, unsigned short _IN3, unsigned short _IN4, unsigned short _ENA, unsigned short _ENB){
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

void L298N::power(unsigned vel){
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
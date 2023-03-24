#include "L298.h"
#include "HC-SR04.h"
#include "PinChangeInterrupt.h"

#define BTN 9
#define L1 12
#define L2 13
#define threshold 400

long time = 0;
bool on = 0;
HCSR h04 = HCSR(2,3);
L298N motors = L298N(4, 5, 6, 7, 10, 11);

void interrupt(){
  if(millis() - time > threshold) on = !on;
}

void setup(){
  motors.power(0);
  pinMode(BTN, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  digitalWrite(L1, 0);
  digitalWrite(L2, 0);

  Serial.begin(9600);
    
  attachPCINT(digitalPinToPCINT(BTN), interrupt, RISING);
}

void loop(){
  if(on == 1){
    long dist = h04.read();

    Serial.println(dist);
    
    if(dist < 30){
      motors.back();
      motors.power(127);
      digitalWrite(L1, 1);
      digitalWrite(L2, 0);
    }
    else{
      motors.power(0);      
      digitalWrite(L1, 0);
      digitalWrite(L2, 1);
    }
  }
  else{
    digitalWrite(L1, 0);
    digitalWrite(L2, 0);
  }
}
/*
  Éste programa es el firmware de un robot basado en Arduino UNO.
  Utiliza la libreria PinChangeInterrupt (https://github.com/NicoHood/PinChangeInterrupt)
  y dos librerias propias.
  
  La inención es hacer una practica para el curso de Fundamentos del desarrollo de Hardware
  de platzi.com y también practicar el uso de git y github.
  
  Éste proyecto fue hecho por Francisco Felissia (francsicofelissia@gmail.com).
  Se distribulle bajo la licencia GPLv.3 y se puede obtener desde
  https://github.com/franfelissia/Robot junto con toda la documentación necesaria.
*/
#include <Arduino.h>
#include "L298.h"
#include "HC-SR04.h"
#include "PinChangeInterrupt.h"

// Definimos componentes extras.
#define BTN 9
#define L1 12
#define L2 13

// Definimos algunos datos de la interrupción.
#define threshold 200
long time = 0;
bool on = 0;

// Inicializamos los módulos.
HCSR h04 = HCSR(2,3);
L298N motors = L298N(4, 5, 6, 7, 10, 11);

// Servicio de interrupción
void interrupt(){
  /*
    Si el tiempo transcurido entre la ultima llamada y la llamada actual es mayor al umbral
    entonces se cambia el valor de la variable on.
  */
  if(millis() - time > threshold)
    on = !on;
    time = millis();
}

void setup(){
  motors.power(0);
  pinMode(BTN, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  digitalWrite(L1, 0);
  digitalWrite(L2, 1);
  attachPCINT(digitalPinToPCINT(BTN), interrupt, RISING);

  motors.power(127);
  motors.forward();
}

void loop(){ 
  // Control de encendido y apagado (Se puede mejorar con el modo bajo consumo)
  if(on == 1){
    motors.power(127);
    motors.forward();
    digitalWrite(L1, 0);
    digitalWrite(L2, 1);

    uint8_t dist = h04.read();
    
    // Si se encuentra con algo.
    if(dist < 10){
      
      //Cambia las luces.
      digitalWrite(L1, 1);
      digitalWrite(L2, 0);
      
      //Para.
      motors.power(0);
      
      //Espera.
      delay(500);
      
      //Se hace para atras.
      motors.back();
      motors.power(127);
      delay(500);
      
      //Elige si va para donde ir al azar.
      if(random(2)) motors.left();
      else motors.right();
      delay(random(250, 500));
    }
  }
  else{
    motors.power(0);
    digitalWrite(L1, 0);
    digitalWrite(L2, 0);
  }
}
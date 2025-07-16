#ifndef MOTORES_H
#define MOTORES_H

#include <Arduino.h> //importaca necessaria no platformio
#include <Servo.h>

// Inicializa o servo e o LED
void inicializarSistema();

// Move o servo para um ângulo e pisca o LED
void moverServoEPiscarLED(int angulo);

void atualizarServoComPotenciometro();
#endif

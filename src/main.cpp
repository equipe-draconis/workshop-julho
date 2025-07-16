#include <Arduino.h>
#include "motores.h"

// Defina os pinos usados (ajuste conforme necessário)
const int pinoPot1 = A0;
const int pinoPot2 = A1;

const int pinoServo1 = 9;
const int pinoServo2 = 10;

const int led1 = 4;
const int led2 = 5;

// Servos globais (usados internamente em motores.cpp)
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  delay(500); // Aguarda a inicialização da serial

  inicializarSistema();  // Você pode usar isso para alguma inicialização extra, se quiser
}

void loop() {
  atualizarServoComPotenciometro();  // Atualiza com base nas leituras dos potenciômetros
}

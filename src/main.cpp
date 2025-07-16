#include <Arduino.h> //Importaçao necessaria no platformio
#include "motores.h"

void setup() {
  inicializarSistema();
}

void loop() {
  moverServoEPiscarLED(0);
  moverServoEPiscarLED(90);
  moverServoEPiscarLED(180);
}

#include <Arduino.h> //Importaçao necessaria no platformio
#include "motores.h"

void setup() {
  inicializarSistema();
}



void loop() {
  atualizarServoComPotenciometro();
}

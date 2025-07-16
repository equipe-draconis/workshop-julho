#include "motores.h"


Servo meuServo;
const int pinoServo = 9;
const int pinoPot = A0;

void inicializarSistema(){
  meuServo.attach(9);           // Conecta o servo ao pino 9
  pinMode(LED_BUILTIN, OUTPUT); // Configura o LED
}

void moverServoEPiscarLED(int angulo) {
  digitalWrite(LED_BUILTIN, LOW);  // Apaga LED
  delay(500);
  meuServo.write(angulo);          // Move para o ângulo
  digitalWrite(LED_BUILTIN, HIGH); // Acende LED
  delay(500);
}


void atualizarServoComPotenciometro() {
  int leitura = analogRead(pinoPot);          // Leitura: 0–1023
  int angulo = map(leitura, 0, 1023, 0, 180); // Mapeia para 0–180 graus
  servo.write(angulo);                        // Move servo
  delay(15);                                  // Delay para suavizar movimento
}


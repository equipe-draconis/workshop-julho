#include "motores.h"


Servo meuServo1;
Servo meuServo2;
const int pinoServo1 = 9;
const int pinoPot1 = A0;

const int pinoServo2 = 10;
const int pinoPot2 = A1;

void inicializarSistema(){
   meuServo1.attach(pinoServo1);
   meuServo2.attach(pinoServo2);           // Conecta o servo ao pino 9
  pinMode(LED_BUILTIN, OUTPUT); // Configura o LED
}

void moverServoEPiscarLED(int angulo) {
  digitalWrite(LED_BUILTIN, LOW);  // Apaga LED
  delay(500);
  meuServo1.write(angulo);          // Move para o ângulo
  digitalWrite(LED_BUILTIN, HIGH); // Acende LED
  delay(500);
}
void printAngulo(int angulo, int num_pot){
    // Exibe no Serial Monitor para plotar
  Serial.println("Angulo do potenciometro " + String(num_pot) + ": ");

  Serial.println(angulo);
}

void atualizarServoComPotenciometro() {
  int angulo1 = lerAnguloDoPotenciometro(pinoPot1);
  int angulo2 = lerAnguloDoPotenciometro(pinoPot2);

  moverServoComID(angulo1, 1);
  moverServoComID(angulo2, 2);

  delay(15); // Delay para suavizar movimento
}

int lerAnguloDoPotenciometro(int pinoPot) {
  int leitura = analogRead(pinoPot);
  int A = map(leitura, 0, 1023, 0, 180);               // 0–1023
  return leitura;                                      // 0–180°
}

void moverServoComID(int angulo, int id) {
  moverServoEPiscarLED(angulo);   // Modifique esta função para aceitar ID se necessário
  printAngulo(angulo, id);
}



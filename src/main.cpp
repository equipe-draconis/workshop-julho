#include <Arduino.h>
#include <Servo.h>

// Defina os pinos usados (ajuste conforme necessário)
const int pinoPot1 = A0;
const int pinoPot2 = A1;

const int pinoServo1 = 9;
const int pinoServo2 = 10;



// Servos globais (usados internamente em motores.cpp)
Servo servo1;
Servo servo2;

void setup() {
  Serial.begin(9600);
  delay(500); // Aguarda a inicialização da serial

  servo1.attach(pinoServo1);      // Conecta o servo ao pino 9
  servo2.attach(pinoServo2);        // Conecta o servo ao pino 10
}

void loop() {
  int angulo1 = analogRead(pinoPot1);
  int angulo2 = analogRead(pinoPot2);
  servo1.write(angulo1);          // Move para o ângulo
  servo2.write(angulo2);          // Move para o ângulo

  //Serial.println(angulo1 ,  1);
  delay(500);
  //Serial.println(angulo2, 2);
  //delay(500);

}

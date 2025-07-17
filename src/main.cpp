#include <Arduino.h>
#include <Servo.h>

const int pinoBasePot = A0;
const int pinoCotoveloPot = A1;
const int pinoservoBase = 9;
const int pinoservoCotovelo = 10;
const float L1 = 10.0;
const float L2 = 10.0;

float x_alvo = 15.0;
float y_alvo = 5.0;


Servo servoBase;
Servo servoCotovelo;

void setup() {
  Serial.begin(9600);
  delay(500);

  servoBase.attach(pinoservoBase);
  servoCotovelo.attach(pinoservoCotovelo);
}

void loop() {
  float D = (x_alvo * x_alvo + y_alvo * y_alvo - L1 * L1 - L2 * L2) / (2 * L1 * L2);

  int motor1 = analogRead(pinoBasePot);
  int motor2 = analogRead(pinoCotoveloPot);

  int angulo1_antes = 0;
  int angulo2_antes = 0;

  int angulo1 = map(motor1, 0, 1023, 0, 180);
  int angulo2 = map(motor2, 0, 1023, 0, 180);

  float theta2 = acos(D); // radianos

  // Cálculo de k1 e k2 para theta1
  float k1 = L1 + L2 * cos(theta2);
  float k2 = L2 * sin(theta2);
  float theta1 = atan2(y_alvo, x_alvo) - atan2(k2, k1);


  if ((angulo1 - angulo1_antes)  > 5){
    servoBase.write(angulo1);

  }

    if ((angulo2 - angulo2_antes) > 5){
    servoCotovelo.write(angulo2);
  }
  angulo1_antes = angulo1;
  angulo2_antes = angulo2;

  Serial.print(angulo1);
  Serial.print(",");
  Serial.println(angulo2);


  delay(500);
}

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

  int motor1 = analogRead(pinoBasePot);
  int motor2 = analogRead(pinoCotoveloPot);

  int x_alvo_antes = 0;
  int y_alvo_antes = 0;

  int x_alvo = map(motor1, 0, 1023, 0, 180); // esta é a variavel y?
  int y_alvo = map(motor2, 0, 1023, 0, 180);//esta é a variavel x?

  float D = (x_alvo * x_alvo + y_alvo * y_alvo - L1 * L1 - L2 * L2) / (2 * L1 * L2);
  D = constrain(D, -1.0, 1.0); // evita erro no acos()
  float theta2 = acos(D); // radianos

  // Cálculo de k1 e k2 para theta1
  float k1 = L1 + L2 * cos(theta2);
  float k2 = L2 * sin(theta2);
  float theta1 = atan2(y_alvo, x_alvo) - atan2(k2, k1);


  if ((x_alvo - x_alvo_antes)  > 5){
    servoBase.write(constrain(theta1, 0, 180));// esta linha precisa ser ajustada

  }

    if ((y_alvo - y_alvo_antes) > 5){
    servoCotovelo.write(constrain(theta2, 0, 180));//esta linha precisa ser ajustada
  }
  x_alvo_antes = x_alvo;
  y_alvo_antes = y_alvo;

  Serial.print(x_alvo);
  Serial.print(",");
  Serial.println(y_alvo);


  delay(500);
}

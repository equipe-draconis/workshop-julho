#include <Arduino.h>
#include <Servo.h>

const int pinoBasePot = A0;
const int pinoCotoveloPot = A1;
const int pinoservoBase = 9;
const int pinoservoCotovelo = 10;



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

  if ((x_alvo - x_alvo_antes)  > 5){
    servoBase.write(constrain(x_alvo, 0, 180));// esta linha precisa ser ajustada

  }

    if ((y_alvo - y_alvo_antes) > 5){
    servoCotovelo.write(constrain(y_alvo, 0, 180));//esta linha precisa ser ajustada
  }
  x_alvo_antes = x_alvo;
  y_alvo_antes = y_alvo;

  Serial.print(x_alvo);
  Serial.print(",");
  Serial.println(y_alvo);


  delay(500);
}

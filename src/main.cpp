#include <Arduino.h>
#include <Servo.h>

Servo meuServo;

void setup() {
     meuServo.attach(9);   // Conecta no pino 9
     meuServo.write(90);   // Vai para 90 graus
       pinMode(LED_BUILTIN, OUTPUT); // LED interno do Arduino Uno
}

void loop() {
    meuServo.write(0);   // Vai para 0 graus
    digitalWrite(LED_BUILTIN, HIGH); // Acende o LED
    delay(500);                      // Espera 500 ms
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);  // Apaga o LED
    delay(500);


    meuServo.write(90);  // Vai para 90 graus
    digitalWrite(LED_BUILTIN, HIGH); // Acende o LED
    delay(500);                      // Espera 500 ms
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);  // Apaga o LED
    delay(500);


    meuServo.write(180); // Vai para 180 graus
    digitalWrite(LED_BUILTIN, HIGH); // Acende o LED
    delay(500);                      // Espera 500 ms
    delay(1000);
    2;
}

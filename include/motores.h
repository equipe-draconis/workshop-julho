#ifndef MOTORES_H
#define MOTORES_H

#include <Arduino.h>
#include <Servo.h>

// Inicializa os servos e LEDs
void inicializarSistema();

// Move o servo identificado por 'id' para um ângulo e pisca o LED correspondente
void moverServoEPiscarLED(int angulo, int id);

// Imprime o ângulo e o número do potenciômetro
void printAngulo(int angulo, int num_pot);

// Atualiza os dois servos com base nos potenciômetros
void atualizarServoComPotenciometro();

// Lê o ângulo do potenciômetro a partir do pino especificado
int lerAnguloDoPotenciometro(int pinoPot);

// Envolve o movimento e impressão de um único servo/potenciômetro
void moverServoComID(int angulo, int id);

#endif // MOTORES_H

# Braço Robótico com 2 Graus de Liberdade - Cinemática Direta no Arduino

Este projeto implementa a cinemática direta de um braço robótico com dois servo motores controlados por potenciômetros, utilizando Arduino.

## 🎯 Objetivo

Calcular a posição (x, y) da extremidade (efetuador) de um braço robótico com dois elos (L1 e L2), controlado por dois ângulos (`θ1` e `θ2`) medidos via potenciômetros.

---

## 🤖 Modelo Geométrico

O braço robótico possui dois segmentos (elos) de comprimento conhecido:

- Elo 1: comprimento `L1`
- Elo 2: comprimento `L2`
- Ângulos:
  - `θ1`: ângulo do primeiro servo em relação ao eixo horizontal
  - `θ2`: ângulo relativo entre o primeiro e o segundo elo

A posição da extremidade do braço é dada pelas equações da cinemática direta:

```math
x = L1 * cos(θ1) + L2 * cos(θ1 + θ2)
y = L1 * sin(θ1) + L2 * sin(θ1 + θ2)

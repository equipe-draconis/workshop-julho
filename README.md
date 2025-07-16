# Controle de Servo com Potenciômetro — Projeto Arduino Modularizado

Este projeto demonstra como controlar um servo motor usando um potenciômetro, com o código organizado de forma modular em arquivos `.h` e `.cpp`, seguindo boas práticas de desenvolvimento com o PlatformIO.

---

## 📦 Estrutura do Projeto

├── include/
│ └── controle_servo.h # Cabeçalho com declarações das funções
├── src/
│ ├── controle_servo.cpp # Implementação da lógica de controle do servo
│ └── main.cpp # Função principal setup() e loop()
└── platformio.ini # Configuração do ambiente PlatformIO


---

## 🔧 Funcionalidade

- O projeto lê a posição de um **potenciômetro** conectado ao pino **A0**.
- Mapeia essa leitura analógica (0–1023) para um ângulo de **0 a 180 graus**.
- Um **servo motor** conectado ao pino **9** é movimentado suavemente de acordo com essa leitura.
- Toda a lógica de controle está encapsulada em funções separadas para melhor organização e reutilização.

---

## 🔌 Conexões

| Componente     | Pino do Arduino |
|----------------|-----------------|
| Servo Motor    | D9 (PWM)        |
| Potenciômetro  | A0              |
| VCC Potenciómetro | 5V          |
| GND Potenciómetro | GND         |

---

## 📁 Detalhes dos Arquivos

### `include/controle_servo.h`
Declara duas funções:
- `inicializarServo()` – Configura o servo.
- `atualizarServoComPotenciometro()` – Lê o potenciômetro e move o servo.

### `src/controle_servo.cpp`
Implementa a lógica de:
- Leitura analógica.
- Conversão para ângulo.
- Escrita no servo motor.
- Delay suave para evitar jitter.

### `src/main.cpp`
Contém o `setup()` e o `loop()` que apenas chamam as funções do módulo para manter o código principal limpo e simples.

---

## ⚙️ Requisitos

- **Arduino Uno** (ou outro compatível)
- **Servo motor padrão (180°)**
- **Potenciômetro linear**
- **PlatformIO** instalado no VS Code ou outro editor compatível

---

## ▶️ Como Compilar e Enviar

1. Instale o [PlatformIO](https://platformio.org/install).
2. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/projeto-servo-potenciometro.git

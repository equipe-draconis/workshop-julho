import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import collections

# === CONFIGURAÇÕES ===
PORTA = '/dev/ttyUSB0'
BAUD = 9600             # Igual ao definido no Arduino
INTERVALO = 50          # Tempo entre atualizações (ms)
TAM_JANELA = 100        # Número de pontos no gráfico

# === INICIALIZA SERIAL ===
try:
    ser = serial.Serial(PORTA, BAUD, timeout=1)
    print(f"Conectado em {PORTA}")
except:
    print(f"Erro ao abrir {PORTA}")
    exit(1)

# === DADOS INICIAIS ===
dados = collections.deque([0] * TAM_JANELA, maxlen=TAM_JANELA)

# === CONFIGURAÇÃO DO PLOT ===
plt.style.use('ggplot')  # tema claro e bonito
fig, ax = plt.subplots()
linha, = ax.plot(dados, lw=2)
ax.set_title("Leitura da Porta Serial em Tempo Real")
ax.set_ylim(0, 1023)  # ajuste conforme seu sensor

# === FUNÇÃO DE ATUALIZAÇÃO ===
def atualizar(frame):
    try:
        linha_serial = ser.readline().decode('utf-8').strip()
        if linha_serial:
            valor = float(linha_serial)
            dados.append(valor)
            linha.set_ydata(dados)
    except Exception as e:
        print("Erro:", e)
    return linha,

# === ANIMAÇÃO ===
ani = FuncAnimation(fig, atualizar, interval=INTERVALO, blit=True)
plt.show()

import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import collections
import re  # para extrair números com regex

# === CONFIGURAÇÕES ===
PORTA = '/dev/ttyUSB0'
BAUD = 9600             # Igual ao definido no Arduino
INTERVALO = 50          # Tempo entre atualizações (ms)
TAM_JANELA = 100        # Número de pontos no gráfico

# === INICIALIZA SERIAL ===
try:
    ser = serial.Serial(PORTA, BAUD, timeout=1)
    print(f"✅ Conectado em {PORTA}")
except Exception as e:
    print(f"❌ Erro ao abrir {PORTA}: {e}")
    exit(1)

# === DADOS INICIAIS ===
dados = collections.deque([0] * TAM_JANELA, maxlen=TAM_JANELA)

# === CONFIGURAÇÃO DO PLOT ===
plt.style.use('ggplot')
fig, ax = plt.subplots()
linha, = ax.plot(dados, lw=2)
ax.set_title("Leitura da Porta Serial em Tempo Real")
ax.set_ylim(0, 1023)
ax.set_ylabel("Valor Lido")
ax.set_xlabel("Tempo (pontos)")

# === FUNÇÃO DE ATUALIZAÇÃO ===
def atualizar(frame):
    try:
        linha_serial = ser.readline().decode('utf-8').strip()
        if linha_serial:
            print(f"Recebido: {linha_serial}")

            # Extrai o primeiro número encontrado na linha (inteiro ou float)
            encontrado = re.search(r"[-+]?\d*\.?\d+", linha_serial)
            if encontrado:
                valor = float(encontrado.group())
                dados.append(valor)
                linha.set_ydata(dados)
    except Exception as e:
        print("Erro na leitura ou conversão:", e)
    return linha,

# === ANIMAÇÃO ===
ani = FuncAnimation(fig, atualizar, interval=INTERVALO, blit=True)
plt.show()

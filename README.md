# 📊 Monitoramento de Semáforos: Via Única e Cruzamento Duplo

Este projeto consiste em uma análise comparativa entre dois sistemas de sinalização viária automatizados para Arduino. O objetivo é avaliar a eficiência lógica, o consumo de recursos de hardware (I/O) e o comportamento do barramento de dados ao escalar a complexidade do circuito.

---

## 🚀 Funcionalidades Analisadas

* **Cenário 1 (Semáforo Simples):** Ciclo linear tradicional (Verde, Amarelo e Vermelho) voltado para o controle de uma única via ou passagem de pedestres.
* **Cenário 2 (Cruzamento Duplo):** Sistema sincronizado de duas vias concorrentes. A lógica impede colisões garantindo que uma via permaneça fechada enquanto a outra está em fluxo ou transição.
* **Telemetria Serial:** Ambos os códigos realizam o envio em tempo real dos estados atuais da sinalização via USB para diagnóstico de transição de dados.

---

## 🛠️ Componentes e Tecnologias

### Hardware Mapeado
* 1x Placa Arduino (Uno, Nano, Mega, etc.)
* Até 6x LEDs (2x Vermelhos, 2x Amarelos, 2x Verdes)
* Resistores de 220Ω (para limitação de corrente dos LEDs)
* Cabos Jumper

### Software
* **Arduino IDE** (Linguagem C/C++)
* **Monitor Serial** (Velocidade de 9600 bps para coleta de logs)

---

## 🔌 Esquema de Ligação (Hardware por Cenário)

Dependendo de qual firmware for carregado no microcontrolador, a distribuição física dos pinos digitais segue as tabelas de alocação de I/O abaixo:

### Tabela de Pinos - Cenário 1 (Semáforo Simples)

| Componente | Função / Estado | Conexão no Arduino |
| :--- | :--- | :--- |
| **LED Verde** | Sinal de Siga (Fluxo Livre) | Pino Digital 2 |
| **LED Amarelo** | Sinal de Atenção (Transição) | Pino Digital 4 |
| **LED Vermelho** | Sinal de Pare (Retenção) | Pino Digital 7 |

### Tabela de Pinos - Cenário 2 (Cruzamento Duplo)

| Semáforo do Cruzamento | Cor do LED | Conexão no Arduino |
| :--- | :--- | :--- |
| **Semáforo 1 (Via A)** | Vermelho 1 | Pino Digital 7 |
| | Amarelo 1 | Pino Digital 4 |
| | Verde 1 | Pino Digital 2 |
| **Semáforo 2 (Via B)** | Vermelho 2 | Pino Digital 13 |
| | Amarelo 2 | Pino Digital 12 |
| | Verde 2 | Pino Digital 8 |

> ⚠️ **Nota de Hardware:** O Cenário 2 consome o dobro de saídas digitais do microcontrolador em comparação ao Cenário 1, exigindo atenção ao limite de corrente total fornecido pela placa.

---

## 💻 Como Executar e Testar

1. Abra a **Arduino IDE**.
2. Escolha um dos dois códigos do repositório (Simples ou Cruzamento) e cole-o na área de desenvolvimento.
3. Monte o circuito físico correspondente em sua matriz de contatos (Protoboard) conforme as tabelas de pinagem acima.
4. Conecte o Arduino ao computador via cabo USB, selecione a placa e a porta correta em *Ferramentas* e clique em **Carregar (Upload)**.
5. Abra o **Monitor Serial** (Ctrl+Shift+M) configurado para a velocidade de **9600 bps** para acompanhar as mensagens de telemetria enviadas pelo circuito.

---

## 📊 Estrutura e Métricas dos Cenários

### Análise Lógica do Firmware
Ambos os programas utilizam funções exclusivas chamadas `semaforo()` para isolar a máquina de estados do laço principal `loop()`. A diferença prática está na temporização fixa e na duração de cada etapa do processamento síncrono:

* **Métrica de Ciclo (Cenário 1):** Possui tempo total de retenção de **5.000 ms** (5 segundos) por ciclo completo, divididos entre os três LEDs em uma estrutura linear simples.
* **Métrica de Ciclo (Cenário 2

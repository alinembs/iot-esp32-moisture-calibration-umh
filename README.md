# Calibration_UMH (ESP32)

## Sobre o projeto
Este projeto embarcado (PlatformIO/Arduino) faz a **leitura de um sensor de umidade** conectado a um pino analógico do ESP32 e **imprime no Serial Monitor**:
- valor bruto do ADC (0–4095)
- percentual de umidade (mapeado entre níveis “dry” e “wet”)
- tensão estimada (com referência de 3,3V)

Ele é voltado para **calibração/observação** do comportamento do sensor (ex.: identificar os valores “seca/molhada” para ajustar o mapeamento).

## Funcionalidades
- Leitura do ADC do pino analógico configurado.
- Conversão para:
  - percentual (linear entre `dry` e `wet`)
  - tensão estimada em volts
- Saída periódica no Serial Monitor (intervalo fixo).

## Estrutura do projeto
```
Calibration_UMH/
├─ include/
│  └─ README
├─ lib/
│  └─ README
├─ test/
│  └─ README
├─ src/
│  ├─ main.cpp
│  └─ calibration_umh.cpp
└─ platformio.ini
```

> Observação: o arquivo `src/main.cpp` pode conter o código final do firmware; já o arquivo `src/calibration_umh.cpp` funciona como uma implementação/variante de leitura e cálculo.

## Interface web
Não há interface web neste projeto. A comunicação/depuração é feita via **Serial (USB)**.

## Como configurar e rodar
### Pré-requisitos
- VS Code + extensão PlatformIO (opcional) ou PlatformIO CLI.
- Toolchain do PlatformIO para ESP32.

### Configuração (PlatformIO)
O projeto está configurado em `platformio.ini` para:
- **board**: `esp32doit-devkit-v1`
- **framework**: `arduino`
- **monitor_speed**: `115200`

### Conexões (sensor)
- Conecte a saída analógica do sensor ao pino **ADC** definido no código (ex.: `AOUT_PIN 36`).
- GND e VCC conforme o sensor utilizado (verifique a documentação do seu hardware).

### Build e upload
No diretório do projeto:
- `pio run`
- `pio run --target upload`

### Visualizar dados
- Abra o **Serial Monitor** na velocidade **115200**.
- O firmware imprime periodicamente:
  - `Moisture value: <ADC>`
  - `Percentual: <%>`
  - `Tensão: <V>`

## Diagrama da arquitetura (ASCII)
```
+--------------------+
|     Sensor         |
|  (umidade -> AOUT) |
+---------+----------+
          |
          | analog in
          v
+--------------------+      Serial prints
|   ESP32 (ADC)      |----------------------->
|  src/main.cpp/     |
|  calibration_umh.cpp
+--------------------+
          |
          | (loop)
          v
+--------------------+
| Serial Monitor     |
| (115200 bps)       |
+--------------------+
```

## Parâmetros de calibração
O cálculo do percentual usa dois pontos de referência no código:
- `dry` : valor ADC associado à condição “seca”
- `wet` : valor ADC associado à condição “molhada”

Ajuste esses valores conforme suas medições (ex.: usando logs do Serial Monitor para determinar os ADC correspondentes à realidade do seu sensor).

### 👥 Colaboradores

As seguintes pessoas contribuíram para o desenvolvimento deste projeto:

<table> <tr> <td align="center"> <a href="https://github.com/alinembs"> <img src="https://avatars.githubusercontent.com/alinembs" width="100px;" alt="Foto da Aline Mariana no GitHub"/><br> <sub><b>Aline Mariana Barros Silva</b></sub> </a> </td> </tr> </table>
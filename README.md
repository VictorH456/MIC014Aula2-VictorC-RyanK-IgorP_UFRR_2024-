---

# MIC014Aula4-VictorC-RyanK-IgorP_UFRR_2024

<br />  
<p align="center">
  <a href="">
    <img src="https://user-images.githubusercontent.com/49700354/114078715-a61b2f00-987f-11eb-8eef-6fd7cfc17d33.png" alt="" width="80" height="80">
    <img src="https://github.com/VictorH456/MIC014Aula2-VictorC-RyanK-IgorP_UFRR_2024/blob/main/imagens/maloca.png" alt="" width="80" height="80">
    <img src="https://github.com/VictorH456/MIC014Aula2-VictorC-RyanK-IgorP_UFRR_2024/blob/main/imagens/dcc.png" alt="" width="80" height="80">
  </a>
  <h1 align="center">Projeto de Dispenser para Higienização das mãos</h1>
  <p align="center">
    <img src="https://github.com/VictorH456/MIC014Aula2-VictorC-RyanK-IgorP_UFRR_2024-/blob/main/imagens/Kakapo_lavando.jpg">
    

## 1. Dispenser de Higienização das Mãos

O projeto a ser desenvolvido consiste na criação de um **dispenser automático de higienização das mãos** utilizando o microcontrolador **ESP32**. O sistema será composto por três componentes principais: um **sensor ultrassônico**, um **motor de bomba** e uma **luz indicadora**.

Quando o sensor ultrassônico detectar a presença das mãos, o **motor de bomba** será acionado para liberar o álcool gel ou sabonete, enquanto a **luz indicadora** sinaliza que o dispenser está funcionando. Este sistema será útil em ambientes hospitalares e outros locais públicos, garantindo um processo de higienização eficiente e sem contato.

O desenvolvimento será realizado na plataforma **Arduino IDE**, utilizando a programação do ESP32 para controlar a interação entre o sensor, a bomba e a luz indicadora, criando uma solução prática e segura para a higienização das mãos.

### 1.1 Objetivos:
- Criar um dispenser automático de higienização das mãos eficiente e sem contato.
- Integrar o ESP32 com os componentes (sensor ultrassônico, motor de bomba e luz indicadora).
- Desenvolver a programação para acionar os dispositivos corretamente quando as mãos forem detectadas.
- Explorar o uso do ESP32 em sistemas automáticos de higiene.

## 2. Tutorial de Montagem:
- **Sensor Ultrassônico**: Conecte o pino **Trig** ao pino digital 21 do ESP32 e o pino **Echo** ao pino digital 22. O VCC do sensor vai ao **5V** e o GND ao **GND**.
- **Motor de Bomba**: Conecte o **VCC** do motor à alimentação e o **GND** ao GND do ESP32. O pino de controle do motor vai ao pino digital 23 do ESP32.
- **Luz Indicadora (LED)**: Conecte o anodo do LED ao resistor, que será ligado ao pino 19 do ESP32, e o catodo ao GND.
- **Alimentação**: A alimentação pode ser feita via cabo USB ou por uma fonte externa compatível.

</p>
</p>
</p>

---

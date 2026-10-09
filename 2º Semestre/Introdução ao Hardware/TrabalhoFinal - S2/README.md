# Cancela Automática com Arduino UNO

Projeto acadêmico de desenvolvimento de uma **cancela automática para estacionamentos**, utilizando Arduino UNO, sensor ultrassônico HC-SR04 e micro servo SG90. O sistema detecta a aproximação de veículos, controla a abertura e o fechamento da cancela e fornece sinalização visual e sonora ao usuário.

## Objetivo do Projeto

Desenvolver um sistema automatizado para estacionamentos de pequeno porte, como condomínios, empresas e universidades, reduzindo filas e a necessidade de acionamento manual por um porteiro ou responsável.


## Funcionamento do Sistema

O sistema utiliza a distância medida pelo sensor ultrassônico para determinar quando a cancela deve abrir ou fechar.

- **Detecção do veículo:** o sensor HC-SR04 mede a distância até o veículo.
- **Abertura automática:** quando a distância fica abaixo de 20 cm por 3 leituras consecutivas, a cancela é acionada.
- **Movimentação da cancela:** o servo motor movimenta a cancela até 90° para abrir e 0° para fechar.
- **Sinalização visual:** o LED verde indica que a cancela está aberta, enquanto o LED vermelho indica que está fechada.
- **Sinalização sonora:** o buzzer emite bipes durante a abertura e o fechamento.
- **Fechamento automático:** após 3 segundos sem detectar um veículo, o sistema inicia o fechamento, verificando se ainda existe um veículo próximo.
- **Monitor Serial:** permite acompanhar as leituras do sensor e o estado da cancela.

Leituras inválidas, como ausência de eco ou valores fora do alcance do sensor, são ignoradas.

## Sensores e Atuadores

| Componente | Função |
|---|---|
| Arduino UNO | Controla o funcionamento do sistema |
| Sensor ultrassônico HC-SR04 | Mede a distância até o veículo |
| Micro servo SG90 | Movimenta a cancela entre 0° e 90° |
| LED verde | Indica a cancela aberta |
| LED vermelho | Indica a cancela fechada |
| Buzzer piezoelétrico | Emite sinais sonoros |
| Resistores de 220 Ω | Limitam a corrente dos LEDs |
| Protoboard e jumpers | Realizam as conexões do circuito |
| Cabo USB | Alimentação e comunicação com o computador |

## Materiais Necessários

- 1 Arduino UNO e cabo USB
- 1 protoboard
- Jumpers para conexão
- 1 sensor ultrassônico HC-SR04
- 1 micro servo SG90
- 1 LED verde
- 1 LED vermelho
- 2 resistores de 220 Ω
- 1 buzzer piezoelétrico

**Disponibilidade dos materiais:** o Arduino, a protoboard, os jumpers, os LEDs, os resistores e o buzzer serão fornecidos pelo curso. O sensor ultrassônico e o micro servo serão adquiridos em lojas.

## Diferenciais do Projeto

Além do funcionamento básico de uma cancela automática, o projeto prevê melhorias para tornar o sistema mais seguro e informativo:

- Confirmação da presença do veículo por leituras consecutivas.
- Movimento suave do servo motor.
- Sinalização visual e sonora dos estados da cancela.
- Contador de veículos.
- Verificação da presença de veículos antes do fechamento.
- Monitoramento das informações pelo Monitor Serial.


## Integrantes e Responsabilidades

| Integrante | Responsabilidade |
|---|---|
| Bruno Siemer | Elaboração do documento de proposta e vídeo demonstrativo |
| Vitor Benetti | Elaboração do projeto no Tinkercad |
| Lucas Riva | Elaboração do relatório final |
| Ray Alvez | Elaboração do relatório final |


## TINKERCAD
https://www.tinkercad.com/things/3RgD19BytQl-surprising-hillar
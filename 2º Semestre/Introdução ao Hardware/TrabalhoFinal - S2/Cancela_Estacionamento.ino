

#include <Servo.h>

#define PINO_TRIG          9
#define PINO_ECHO          10
#define PINO_SERVO         6
#define PINO_LED_VERDE     4
#define PINO_LED_VERMELHO  5
#define PINO_BUZZER        3

#define DISTANCIA_LIMITE_CM   20.0
#define LEITURAS_CONFIRMACAO  3
#define TEMPO_FECHAR_MS       3000UL
#define ANGULO_FECHADA        0
#define ANGULO_ABERTA         90
#define PASSO_SERVO_MS        15
#define INTERVALO_LEITURA_MS  100
#define FREQ_BIPE             1000

Servo cancela;
bool aberta = false;
int anguloAtual = ANGULO_FECHADA;
int leiturasPerto = 0;
unsigned long ultimoCarroVisto = 0;
unsigned long contadorVeiculos = 0;

float medirDistancia() {
  digitalWrite(PINO_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PINO_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PINO_TRIG, LOW);

  unsigned long duracao = pulseIn(PINO_ECHO, HIGH, 30000UL);
  if (duracao == 0) return -1;

  float distancia = duracao * 0.0343 / 2.0;
  if (distancia < 2 || distancia > 400) return -1;
  return distancia;
}

bool carroPresente() {
  float d = medirDistancia();
  return d > 0 && d < DISTANCIA_LIMITE_CM;
}


void bipe(int vezes) {
  for (int i = 0; i < vezes; i++) {
    tone(PINO_BUZZER, FREQ_BIPE);
    delay(150);
    noTone(PINO_BUZZER);
    delay(100);
  }
}

void ledsAberta() {
  digitalWrite(PINO_LED_VERDE, HIGH);
  digitalWrite(PINO_LED_VERMELHO, LOW);
}

void ledsFechada() {
  digitalWrite(PINO_LED_VERDE, LOW);
  digitalWrite(PINO_LED_VERMELHO, HIGH);
}

void moverServo(int destino) {
  while (anguloAtual != destino) {
    anguloAtual += (destino > anguloAtual) ? 1 : -1;
    cancela.write(anguloAtual);
    delay(PASSO_SERVO_MS);
  }
}

void abrirCancela() {
  Serial.println(">> Abrindo cancela");
  ledsAberta();
  bipe(1);
  moverServo(ANGULO_ABERTA);

  aberta = true;
  leiturasPerto = 0;
  contadorVeiculos++;
  ultimoCarroVisto = millis();

  Serial.print("Cancela ABERTA | Veiculos: ");
  Serial.println(contadorVeiculos);
}

void fecharCancela() {
  Serial.println(">> Fechando cancela");
  bipe(2);

  while (anguloAtual > ANGULO_FECHADA) {
    anguloAtual--;
    cancela.write(anguloAtual);
    delay(PASSO_SERVO_MS);

    if (anguloAtual % 10 == 0 && carroPresente()) {
      Serial.println("!! Veiculo detectado durante fechamento - reabrindo");
      bipe(1);
      moverServo(ANGULO_ABERTA);
      ledsAberta();
      ultimoCarroVisto = millis();
      return; 
    }
  }

  aberta = false;
  leiturasPerto = 0;
  ledsFechada();
  Serial.println("Cancela FECHADA");
}


void autoteste() {
  Serial.println("Autoteste: LED verde, LED vermelho, buzzer...");
  digitalWrite(PINO_LED_VERDE, HIGH);
  delay(400);
  digitalWrite(PINO_LED_VERDE, LOW);
  digitalWrite(PINO_LED_VERMELHO, HIGH);
  delay(400);
  digitalWrite(PINO_LED_VERMELHO, LOW);
  bipe(1);
}

void setup() {
  Serial.begin(9600);

  pinMode(PINO_TRIG, OUTPUT);
  pinMode(PINO_ECHO, INPUT);
  pinMode(PINO_LED_VERDE, OUTPUT);
  pinMode(PINO_LED_VERMELHO, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);
  digitalWrite(PINO_TRIG, LOW);

  cancela.attach(PINO_SERVO);
  cancela.write(ANGULO_FECHADA);
  anguloAtual = ANGULO_FECHADA;

  autoteste();
  ledsFechada();
  Serial.println("Cancela automatica pronta.");
}

void loop() {
  float d = medirDistancia();

  if (d < 0) {                
    delay(INTERVALO_LEITURA_MS);
    return;
  }

  Serial.print("Distancia: ");
  Serial.print(d);
  Serial.print(" cm | Cancela: ");
  Serial.println(aberta ? "ABERTA" : "FECHADA");

  bool perto = d < DISTANCIA_LIMITE_CM;

  if (!aberta) {
    leiturasPerto = perto ? leiturasPerto + 1 : 0;
    if (leiturasPerto >= LEITURAS_CONFIRMACAO) {
      abrirCancela();
    }
  } else {
    if (perto) {
      ultimoCarroVisto = millis();
    } else if (millis() - ultimoCarroVisto >= TEMPO_FECHAR_MS) {
      fecharCancela();
    }
  }

  delay(INTERVALO_LEITURA_MS);
}

const int carroVerde = 13;
const int carroAmarelo = 12;
const int carroVermelho = 11;

const int pedestreVerde = 10;
const int pedestreVermelho = 9;

const int botao = 7;

void setup() {

  pinMode(carroVerde, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVermelho, OUTPUT);

  pinMode(pedestreVerde, OUTPUT);
  pinMode(pedestreVermelho, OUTPUT);

  pinMode(botao, INPUT_PULLUP);

  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);
}

void loop() {
  
  digitalWrite(carroVerde, HIGH);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, LOW);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);
  
    if(digitalRead(botao) == LOW) {
      delay(5000);
      passagemPedestres();

      return;
    }

  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);
  digitalWrite(carroVermelho, LOW);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);

  delay(2000);

  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, HIGH);

  digitalWrite(pedestreVerde, HIGH);
  digitalWrite(pedestreVermelho, LOW);

  delay(5000);

  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroVerde, HIGH);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);
}


void passagemPedestres() {

  digitalWrite(carroVerde, LOW);
  digitalWrite(carroAmarelo, HIGH);
  digitalWrite(carroVermelho, LOW);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);
  delay(2000);

  digitalWrite(carroAmarelo, LOW);
  digitalWrite(carroVermelho, HIGH);

  digitalWrite(pedestreVermelho, LOW);
  digitalWrite(pedestreVerde, HIGH);
  delay(5000);

  digitalWrite(pedestreVerde, LOW);
  digitalWrite(pedestreVermelho, HIGH);

  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroVerde, HIGH);
  delay(300);
}
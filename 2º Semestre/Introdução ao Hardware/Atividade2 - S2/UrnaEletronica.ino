#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int BOTAO_PEDRO = A2;
const int BOTAO_PAULO = A3;
const int BOTAO_JOAO  = A4;
const int BOTAO_MARIA = A5;

const int BUZZER = 8;

const String SENHA_VOTE = "Vote";
const String COMANDO_DISPLAY = "Display";
const String COMANDO_FIM = "Fim";

const int TEMPO_DEBOUNCE = 200;
const int TEMPO_CONFIRMACAO = 3000;
const int TEMPO_APURACAO = 2000;

enum Estado {
  BLOQUEADA,
  LIBERADA,
  CONFIRMANDO,
  ENCERRADA
};

Estado estadoAtual = BLOQUEADA;

int votosPedro = 0;
int votosPaulo = 0;
int votosJoao = 0;
int votosMaria = 0;

void setup() {

  Serial.begin(9600);

  lcd.begin(16, 2);
  
  pinMode(BOTAO_PEDRO, INPUT_PULLUP);
  pinMode(BOTAO_PAULO, INPUT_PULLUP);
  pinMode(BOTAO_JOAO, INPUT_PULLUP);
  pinMode(BOTAO_MARIA, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);
  
  mostrarBloqueada();

  Serial.println("================================");
  Serial.println("       URNA ELETRONICA");
  Serial.println("================================");
  Serial.println("Urna iniciada e bloqueada.");
  Serial.println("Digite Vote para liberar um voto.");
}

void loop() {

  verificarComandos();

  if (estadoAtual == LIBERADA) {
    verificarBotoes();
  }
}

void verificarComandos() {

  if (Serial.available() > 0) {

    String comando = Serial.readStringUntil('\n');

    comando.trim();

    if (comando == COMANDO_FIM) {

      encerrarVotacao();

      return;
    }
    
    if (comando == COMANDO_DISPLAY) {

      mostrarApuracao();

      return;
    }

    if (comando == SENHA_VOTE) {

      if (estadoAtual == BLOQUEADA) {

        estadoAtual = LIBERADA;

        lcd.clear();

        lcd.setCursor(0, 0);
        lcd.print("Votacao liberada");

        lcd.setCursor(0, 1);
        lcd.print("Escolha candidato");

        Serial.println("Votacao liberada.");
        Serial.println("Aguardando voto.");

      }

      else if (estadoAtual == LIBERADA) {

        Serial.println("Ja existe um voto liberado.");

      }

      else if (estadoAtual == CONFIRMANDO) {

        Serial.println("Aguarde a confirmacao do voto.");

      }

      else if (estadoAtual == ENCERRADA) {

        Serial.println("Votacao encerrada.");

      }

      return;
    }

    Serial.println("Comando ou senha incorreta.");
  }
}

void verificarBotoes() {

  if (digitalRead(BOTAO_PEDRO) == LOW) {

    delay(TEMPO_DEBOUNCE);

    if (digitalRead(BOTAO_PEDRO) == LOW) {
      registrarVoto("Pedro");

      while (digitalRead(BOTAO_PEDRO) == LOW) {
        delay(10);
      }
    }

    return;
  }


  if (digitalRead(BOTAO_PAULO) == LOW) {

    delay(TEMPO_DEBOUNCE);

    if (digitalRead(BOTAO_PAULO) == LOW) {
      registrarVoto("Paulo");

      while (digitalRead(BOTAO_PAULO) == LOW) {
        delay(10);
      }
    }

    return;
  }


  if (digitalRead(BOTAO_JOAO) == LOW) {

    delay(TEMPO_DEBOUNCE);

    if (digitalRead(BOTAO_JOAO) == LOW) {
      registrarVoto("Joao");

      while (digitalRead(BOTAO_JOAO) == LOW) {
        delay(10);
      }
    }

    return;
  }


  if (digitalRead(BOTAO_MARIA) == LOW) {

    delay(TEMPO_DEBOUNCE);

    if (digitalRead(BOTAO_MARIA) == LOW) {
      registrarVoto("Maria");

      while (digitalRead(BOTAO_MARIA) == LOW) {
        delay(10);
      }
    }

    return;
  }
}

void somUrna() {
  for (int i = 0; i < 7; i++) {
    tone(BUZZER, 2200);
    delay(100);

    tone(BUZZER, 2300);
    delay(100);
  }

  noTone(BUZZER);
}

void registrarVoto(String candidato) {

  estadoAtual = CONFIRMANDO;

  if (candidato == "Pedro") {
    votosPedro++;
  }

  else if (candidato == "Paulo") {
    votosPaulo++;
  }

  else if (candidato == "Joao") {
    votosJoao++;
  }

  else if (candidato == "Maria") {
    votosMaria++;
  }

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Voto confirmado");

  lcd.setCursor(0, 1);
  lcd.print(candidato);

  somUrna();
	
  Serial.print("Voto registrado: ");
  Serial.println(candidato);

  delay(TEMPO_CONFIRMACAO);

  estadoAtual = BLOQUEADA;

  mostrarBloqueada();

  Serial.println("Urna bloqueada.");
  Serial.println("Digite Vote para o proximo eleitor.");
}


void mostrarBloqueada() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Urna bloqueada");

  lcd.setCursor(0, 1);
  lcd.print("Aguardando");
}


void mostrarApuracao() {

  Serial.println();
  Serial.println("===== APURACAO =====");

  Serial.print("Pedro: ");
  Serial.println(votosPedro);

  Serial.print("Paulo: ");
  Serial.println(votosPaulo);

  Serial.print("Joao: ");
  Serial.println(votosJoao);

  Serial.print("Maria: ");
  Serial.println(votosMaria);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Pedro: ");
  lcd.print(votosPedro);

  lcd.setCursor(0, 1);
  lcd.print("Paulo: ");
  lcd.print(votosPaulo);

  delay(TEMPO_APURACAO);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Joao: ");
  lcd.print(votosJoao);

  lcd.setCursor(0, 1);
  lcd.print("Maria: ");
  lcd.print(votosMaria);

  delay(TEMPO_APURACAO);

  if (estadoAtual == BLOQUEADA) {
    mostrarBloqueada();
  }

  else if (estadoAtual == LIBERADA) {

    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Votacao liberada");

    lcd.setCursor(0, 1);
    lcd.print("Escolha candidato");
  }

  else if (estadoAtual == ENCERRADA) {
    mostrarResultadoFinal();
  }
}

void encerrarVotacao() {

  estadoAtual = ENCERRADA;

  Serial.println();
  Serial.println("========================");
  Serial.println("   VOTACAO ENCERRADA");
  Serial.println("========================");

  mostrarResultadoFinal();
}

void mostrarResultadoFinal() {

  Serial.println();
  Serial.println("===== RESULTADO FINAL =====");

  Serial.print("Pedro: ");
  Serial.println(votosPedro);

  Serial.print("Paulo: ");
  Serial.println(votosPaulo);

  Serial.print("Joao: ");
  Serial.println(votosJoao);

  Serial.print("Maria: ");
  Serial.println(votosMaria);

  int maior = votosPedro;

  if (votosPaulo > maior) {
    maior = votosPaulo;
  }

  if (votosJoao > maior) {
    maior = votosJoao;
  }

  if (votosMaria > maior) {
    maior = votosMaria;
  }

  int quantidadeVencedores = 0;

  if (votosPedro == maior) {
    quantidadeVencedores++;
  }

  if (votosPaulo == maior) {
    quantidadeVencedores++;
  }

  if (votosJoao == maior) {
    quantidadeVencedores++;
  }

  if (votosMaria == maior) {
    quantidadeVencedores++;
  }

  lcd.clear();

  if (quantidadeVencedores > 1) {

    lcd.setCursor(0, 0);
    lcd.print("Resultado final");

    lcd.setCursor(0, 1);
    lcd.print("Empate!");

    Serial.println("Resultado: EMPATE");
  }

  else {

    String vencedor;

    if (votosPedro == maior) {
      vencedor = "Pedro";
    }

    else if (votosPaulo == maior) {
      vencedor = "Paulo";
    }

    else if (votosJoao == maior) {
      vencedor = "Joao";
    }

    else {
      vencedor = "Maria";
    }

    lcd.setCursor(0, 0);
    lcd.print("Vencedor:");

    lcd.setCursor(0, 1);
    lcd.print(vencedor);

    Serial.print("Vencedor: ");
    Serial.println(vencedor);
  }
}
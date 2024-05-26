/********************************-******************
  Jogo Gênio: um jogo da memória onde você deve 
  repetir a sequência em que luzes acendem.
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/

#include <laboratorioFW-DIY.h>

#define led1 L_0
#define led2 L_1
#define led3 L_2
#define led4 L_3
#define btn1 B_0
#define btn2 B_1
#define btn3 B_2
#define btn4 B_3
#define buzzer P_0

//sons
#define S1 1047
#define S2 1175
#define S3 1319
#define S4 1397
#define SE 2093

int posicoes;
int sequencia[30];

void adicionaNaSequencia(void);
void acendeLed(int n);
void tocaSequencia(void);
void confereSequencia(void);
void tocaErrado(void);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  adicionaNaSequencia();
  delay(700);
  confere();
  delay(800);
}

void adicionaNaSequencia(void) {
  if (posicoes != 0) {
    tocaSequencia();
  }
  randomSeed(millis());//A seed do random vira o tempo atual de execução, o que faz com que as sequencias possam ser diferentes
  sequencia[posicoes] = random(1, 5); //Gera um random entre 1 e 4
  acendeLed(sequencia[posicoes]);
  posicoes++;

}

void acendeLed (int n) { 
  //Os valores 1,2,3,4 são associados ás saídas.
  switch (n) {
    case 1:
      digitalWrite(led1, HIGH);
      tone(buzzer, S1);
      delay(500);
      noTone(buzzer);
      digitalWrite(led1, LOW);
      break;
    case 2:
      digitalWrite(led2, HIGH);
      tone(buzzer, S2);
      delay(500);
      digitalWrite(led2, LOW);
      noTone(buzzer);
      break;
    case 3:
      digitalWrite(led3, HIGH);
      tone(buzzer, S3);
      delay(500);
      digitalWrite(led3, LOW);
      noTone(buzzer);
      break;
    case 4:
      digitalWrite(led4, HIGH);
      tone(buzzer, S4);
      delay(500);
      noTone(buzzer);
      digitalWrite(led4, LOW);
  }
}

void tocaSequencia(void) { 
  for (int i = 0; i < posicoes; i++) {
    acendeLed(sequencia[i]);
    delay(500);
  }
}

void confere(void) {
  int i = 0;
  while (i < posicoes) { 
    bool estaCorreto = (digitalRead(btn1) && sequencia[i] == 1) || (digitalRead(btn2) && sequencia[i] == 2) || (digitalRead(btn3) && sequencia[i] == 3) || (digitalRead(btn4) && sequencia[i] == 4);
    bool estaIncorreto = (digitalRead(btn1) && sequencia[i] != 1) || (digitalRead(btn2) && sequencia[i] != 2) || (digitalRead(btn3) && sequencia[i] != 3) || (digitalRead(btn4) && sequencia[i] != 4);
    if (estaCorreto) {
      acendeLed(sequencia[i]);
      i++;
    }
    else if (estaIncorreto) {
      tocaErrado();
    }
  }
}

void tocaErrado (void) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  tone(buzzer, SE);
  delay(1500);
  noTone(buzzer);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  posicoes = 0;
}

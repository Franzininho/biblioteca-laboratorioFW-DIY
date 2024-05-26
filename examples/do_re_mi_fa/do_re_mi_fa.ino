/********************************-******************
  Aperte um botão para tocar a música dó ré mi fá.
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/

#include <laboratorioFW-DIY.h>

#define ledR L_4
#define ledG L_5
#define ledB L_6
#define buzzer P_0
#define btn B_1

#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_G7  3136


void ligaLED(int r, int g, int b);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(btn, INPUT);
  pinMode(ledR, INPUT);
  pinMode(ledG, INPUT);
  pinMode(ledB, INPUT);
  ligaLED(0, 0, 0);
}

const int tamanho = 32;

int notas[tamanho] = {NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, 0, NOTE_F7, NOTE_F7, 0,
                      NOTE_C7, NOTE_D7, NOTE_C7, NOTE_D7, 0, NOTE_D7, NOTE_D7, 0,
                      NOTE_C7, NOTE_G7, NOTE_F7, NOTE_E7, 0, NOTE_E7, NOTE_E7, 0,
                      NOTE_C7, NOTE_D7, NOTE_E7, NOTE_F7, 0, NOTE_F7, NOTE_F7, 0
                     };

int duracao[tamanho] = {400, 400, 400, 400, 200, 300, 300, 200,
                        400, 400, 400, 400, 200, 300, 300, 200,
                        400, 400, 400, 400, 200, 300, 300, 200,
                        400, 400, 400, 400, 200, 300, 300, 200
                       };

void loop() {
  if (digitalRead(btn)) {
    for (int c = 0; c < tamanho; c++) {
      int nota = notas[c];
      tone(buzzer, nota); 
      switch (nota) {
        case NOTE_C7:
          ligaLED(154, 200, 100);
          break;
        case NOTE_D7:
          ligaLED(0, 200, 0);
          break;
        case NOTE_E7:
          ligaLED(150, 50, 80);
          break;
        case NOTE_F7:
          ligaLED(0, 84, 100);
          break;
        case NOTE_G7:
          ligaLED(30, 30, 200);
          break;
      }
      delay(duracao[c]);
      ligaLED(0, 0, 0);
    }
  }
  else {
    noTone(buzzer);//garante que o buzzer não vai receber nenhum lixo
  }
}

void ligaLED(int r, int g, int b) {
  analogWrite(ledR,r);
  analogWrite(ledG,g);
  analogWrite(ledB,b);
}

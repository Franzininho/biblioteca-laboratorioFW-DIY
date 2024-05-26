/********************************-******************
  Aperte os botões para ver o servo motor se mover em
  direções diferentes.
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/

#include <ESP32_ISR_Servo.h>
#include <laboratorioFW-DIY.h>

#define motor M_0
#define btnEsquerda B_1
#define btnDireita B_3

#define MIN_MICROS 800  //544
#define MAX_MICROS 2450

int escreveEAtualiza(int angulo, int incremento);

int meuServo = ESP32_ISR_Servos.setupServo(motor, MIN_MICROS, MAX_MICROS);

int angulo = 0;

void setup() {
  pinMode(btnEsquerda, INPUT);
  pinMode(btnDireita, INPUT);
}

void loop() {

  if (digitalRead(btnEsquerda)) {
    angulo = escreveEAtualiza(angulo, 10);
  } else if (digitalRead(btnDireita)) {
    angulo = escreveEAtualiza(angulo, -10);
  }
  delay(50);
}

int escreveEAtualiza(int angulo, int incremento) {
  int novoAngulo = angulo + incremento;
  ESP32_ISR_Servos.setPosition(meuServo, novoAngulo);
  return novoAngulo % 180;
}

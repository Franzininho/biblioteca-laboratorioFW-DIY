/********************************-******************
  Controle a cor de um LED RGB através de botões e
  um potenciômetro. 
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/

#include <laboratorioFW-DIY.h>

#define btn1 B_0
#define btn2 B_1
#define btn3 B_2
#define pot S_0
#define r L_4
#define g L_5
#define b L_6

void setup() {
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(pot, INPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  analogWrite(g, 0);
  analogWrite(b, 0);
  analogWrite(r, 0);
}

void loop() {
  int leitura = analogRead(pot);

  int leituraMapeada = map(leitura, 0, 8191, 0, 255);

  if (digitalRead(btn1)) {
    analogWrite(r, leituraMapeada);
  } else if (digitalRead(btn2)) {
    analogWrite(g, leituraMapeada);
  } else  if (digitalRead(btn3)) {
    analogWrite(b, leituraMapeada);
  }


  delay(300);
}

/********************************-******************
  Altere a luminosidade de um LED utilizando o sensor 
  LDR. Um botão pode ser apertado para inverter a 
  lógica de escrita no LED. 
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/

#include <laboratorioFW.h>

#define ldr S_2
#define led L_0

void setup() {
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int leituraMapeada = map(analogRead(ldr), 0, 8191, 0, 255);
  analogWrite(led, 255 - leituraMapeada);
  delay(100);
}

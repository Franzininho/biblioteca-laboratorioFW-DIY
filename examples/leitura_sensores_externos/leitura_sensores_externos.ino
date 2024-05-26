/********************************-******************
  Leitura dos sensores externos conectados através
  dos headers.
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/

#include <laboratorioFW-DIY.h>

#define analogico E_2
#define digital E_3


void setup() {
  pinMode(analogico, INPUT);
  pinMode(digital, INPUT);
  Serial.begin(19200);
}


void loop() {
  Serial.print("Digital - ");
  Serial.print(digitalRead(digital));
  Serial.print(" Analogico - ");
  Serial.println(analogRead(analogico));
  delay(1000);
}

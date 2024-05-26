/********************************-******************
  Exemplo Blink adaptado para a biblioteca
  
  Desenvolvido por Letícia P Garcez - 03/2024
 ****************************************************/
#include <laborarotioFW-DIY.h>

#define led L_1

void setup(){
    pinMode(led,OUTPUT);
}

void loop{
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
}

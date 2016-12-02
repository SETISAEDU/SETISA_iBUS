/*
 * Ejemplo de uso de la libreria "SETISA_iBUS.h"
 * Desarrollada para el uso del puerto iBUS del FS-iA6B
 * Siguenos en facebook como SETISA-EDU https://www.facebook.com/setisaedu/  
 * Suscribete en YouTube como SETISAEDU https://www.youtube.com/channel/UCa7wuIODx6kUsNAnhWqWoYQ 
 * Codigo de ejemplo getChannelValue
 */
//Se incluye la libreria
#include <SETISA_iBUS.h>

//Constructor del objeto
iBUS FlySky;//Se crea el objeto "FlySky"
//Declaracion de vector a donde se alojaran los datos
unsigned int buff[10] = {0};
void setup() {
  // initialize serial:
  Serial.begin(250000); //Para la comunicacion con la PC
  //Mensaje inicial
  Serial.println("iniciando");
  /* FlySky.myPort(3,4,5,6,7,8,9,10,11,12);
   * Sin la declaracion de pines para PWM
   * los pines estan disponibles para su uso como I/O digitales
   */
 
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
}

void loop() 
{
  //Uso de la funcion getChannelValue para obtener los valores de los canales 
  FlySky.getChannelValue(&buff); //Los datos se guardan el la variable buff, que debe tener una longitud de 10
  digitalWrite(3,HIGH); //Comprobacion de uso de los pines como I/O digital
  digitalWrite(5,LOW);
  //Impresion de los datos en el monitor serial
  for (int i = 0; i < 10; i++) 
  {
    Serial.print(buff[i]);//impresion del cada canal
    if (i < 9)Serial.print(", ");//separacion por coma
  }
  Serial.println(); //Salto de linea al finalizar
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  
}

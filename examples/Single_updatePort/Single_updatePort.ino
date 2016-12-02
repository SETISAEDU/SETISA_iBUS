/*
 * Ejemplo de uso de la libreria "SETISA_iBUS.h"
 * desarrollada para el uso del puerto iBUS del FS-iA6B
 * Siguenos en facebook como SETISA-EDU https://www.facebook.com/setisaedu/  
 * Suscribete en YouTube como SETISAEDU https://www.youtube.com/channel/UCa7wuIODx6kUsNAnhWqWoYQ 
 * Cogido de ejemplo Single_updatePort
 */
//Se incluye la libreria
#include <SETISA_iBUS.h>

//Constructor del objeto
iBUS FlySky;//Se crea el objeto "FlySky"

void setup() {
  //Declaracion de los puertos a utilizar como salidas PWM para servo
  FlySky.myPort(3,4,5,6,7,8,9,10,11,12);//Cuando se utilizan para servo no estan disponibles como I/O digitales                                          
  FlySky.setAngle(15,180); //configuracion de los angulos minimos y maximos para los servos 
}

void loop() 
{
  //Uso de la funcion updatePort para mandar los valores de los canales a las salida de los servos 
  FlySky.updatePort(); //La funcion lee e imprime los valores automaticamente  
}

/*
 * Ejemplo de uso de la libreria "SETISA_iBUS.h"
 * Desarrollada para el uso del puerto iBUS del FS-iA6B
 * Siguenos en facebook como SETISA-EDU https://www.facebook.com/setisaedu/  
 * Suscribete en YouTube como SETISAEDU https://www.youtube.com/channel/UCa7wuIODx6kUsNAnhWqWoYQ 
 * Codigo de ejemplo Multiple_angles
 */
//Se incluye la libreria
#include <SETISA_iBUS.h>

//Constructor del objeto
iBUS FlySky;//Se crea el objeto "FlySky"
//Declaracion de la variable de conteo
int x=0;
void setup() {
  //Declaracion de los puertos a utilizar como salidas PWM para servo
  FlySky.myPort(3,4,5,6,7,8,9,10,11,12);//Cuando se utilizan para servo no estan disponibles como I/O digitales                                          
  FlySky.setAngle(0,180); //configuracion de los angulos minimos y maximos para los servos 
}

void loop() 
{
  //Uso de la funcion updatePort para mandar los valores de los canales a las salida de los servos 
  FlySky.updatePort(); //La funcion lee e imprime los valores automaticamente 
  //Funcion de demostracion de cambio de valores de angulo minimo y maximo
  if(x==1000)
  {
    FlySky.setAngle(0,90);
  }else if(x==2000)
  {
    FlySky.setAngle(90,180);
  }
  else if(x==3000)
  {
    FlySky.setAngle(0,180);
    x=0;
  }
  x++;
}

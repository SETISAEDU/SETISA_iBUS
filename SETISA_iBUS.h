/*
 * Libreria para el uso con el puerto iBUS del FS-iA6B
 * Desarrollada por SETISAEDU una division de Electronica y Telecomunicaciones de SETISA
 * Siguenos en facebook como SETISA-EDU https://www.facebook.com/setisaedu/  
 * Suscribete en YouTube como SETISAEDU https://www.youtube.com/channel/UCa7wuIODx6kUsNAnhWqWoYQ 
 */
#include <Servo.h> //Se incluye la libreria para el uso de los servomotores
#include<Arduino.h>  //Librerias de Arduino
//Declaracion de la clase
class iBUS{
   private:
     byte _port1; //Primer Puerto
     byte _port2; //Segundo Puerto
     byte _port3; //Tercer Puerto
     byte _port4; //Cuarto Puerto
     byte _port5; //Quinto Puerto
     byte _port6; //Sexto Puerto
     byte _port7; //Septimo Puerto
     byte _port8; //Octavo Puerto
     byte _port9; //Noveno Puerto
     byte _port10;//Decimo Puerto
     uint8_t _minAngle=15,_maxAngle=180; //iniciacion de las variables de angulo minimo y maximo
     //declaracion de los objetos de los servos
     Servo servo1,servo2,servo3,servo4,servo5,servo6,servo7,servo8,servo9,servo10;
     bool availablePort=0;//Bandera de verificacion de puertos activos
   public:
   iBUS(); //Constructor, se con el que se crea el objeto
   ~iBUS(); //Destructor
   void myPort(byte port1,byte port2,byte port3,byte port4,byte port5,byte port6,byte port7,byte port8,byte port9,byte port10);//Se le pasan los pines a usar como salidas PWM 
   void getChannelValue(void* buf); //Metodo para obtener los valores de los canales
   void setAngle(uint8_t minAngle,uint8_t maxAngle);//Metodo para la configuracion de los angulos minimos y maximos de los servos
   void updatePort(); //Metodo para enviar los valores directamente a los puertos
};

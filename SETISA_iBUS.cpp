/*
 * Libreria para el uso con el puerto iBUS del FS-iA6B
 * Desarrollada por SETISAEDU una division de Electronica y Telecomunicaciones de SETISA
 * Siguenos en facebook como SETISA-EDU https://www.facebook.com/setisaedu/  
 * Suscribete en YouTube como SETISAEDU https://www.youtube.com/channel/UCa7wuIODx6kUsNAnhWqWoYQ 
 * Definicion de la clase y sus metodos
 */
#include <Arduino.h> //Librerias de Arduino.
#include "SETISA_iBUS.h" //Añadimos la declaracion de la clase

//Definicion del constructor
iBUS::iBUS() {
  Serial1.begin(115200);//Inicializacion del puerto serie para leer la salida iBUS del receptor
  }
//Definicion del destructor
iBUS::~iBUS() {}

//Definicion del Primer metodo
void iBUS::myPort(byte port1, byte port2, byte port3, byte port4, byte port5, byte port6, byte port7, byte port8, byte port9, byte port10) {

  this->_port1 = port1;
  this->_port2 = port2;
  this->_port3 = port3;
  this->_port4 = port4;
  this->_port5 = port5;
  this->_port6 = port6;
  this->_port7 = port7;
  this->_port8 = port8;
  this->_port9 = port9;
  this->_port10 = port10;
  availablePort = 1; //Cambio de la bandera indicando que se usaran la salidas PWM
}
//Definicion del Segundo metodo
void iBUS::getChannelValue(void* buf) {

  int trama[32]; //Buffer temporal de la trama
  bool wait = 1; //Bandara de sincronizacion
  uint16_t* current = reinterpret_cast<uint16_t*>(buf);
  while (wait == 1) //Se espera hasta que se termine la sincronizacion de la trama
  {
    while (Serial1.available())
    {
      for (int i = 0; i < 32; i++) //Corrimiento de los 32 datos de la trama
      {
        if (i == 31) {
          trama[i] = Serial1.read(); //Lectura del dato entrante del puerto serial
        }
        else
        {
          trama[i] = trama [i + 1]; //Se corre el dato una posicion
        }
        //Comparacion de sincronia entre los valores constantes de la trama
        if (trama[0] == 0x20 & trama[1] == 0x40 & trama[28] == 0xDC & trama[29] == 0x05)wait = 0;//Bandera de espera en 0 indica que se termino la sincronizacion
      }
    }
  }

  //Cargado de los valores reales de los canales
  //Canal(16bits) = MBS(8bits) + LBS(8bits)
  current[0] = (trama[3] << 8) + trama[2];
  current[1] = (trama[5] << 8) + trama[4];
  current[2] = (trama[7] << 8) + trama[6];
  current[3] = (trama[9] << 8) + trama[8];
  current[4] = (trama[11] << 8) + trama[10];
  current[5] = (trama[13] << 8) + trama[12];
  current[6] = (trama[15] << 8) + trama[14];
  current[7] = (trama[17] << 8) + trama[16];
  current[8] = (trama[19] << 8) + trama[18];
  current[9] = (trama[21] << 8) + trama[20];
}
//Definicion del Tercer metodo
void iBUS::setAngle(uint8_t minAngle, uint8_t maxAngle) {
  _minAngle = minAngle;
  _maxAngle = maxAngle;
}
//Definicion del Cuarto metodo
void iBUS::updatePort() {

  if (availablePort == 1) //Verificacion si se declararon los puertos
  {
    uint8_t trama[32]; //Buffer temporal para la trama
    bool wait = 1;
    uint16_t channel[10];//Buffer temporal para valores de los canales
    while (wait == 1) //Se espera hasta que se termine la sincronizacion de la trama
    {
      while (Serial1.available())
      {
        for (int i = 0; i < 32; i++) //Corrimiento de los 32 datos de la trama
        {
          if (i == 31) {
            trama[i] = Serial1.read(); //Lectura del dato entrante del puerto serial
          }
          else
          {
            trama[i] = trama [i + 1]; //Se corre el dato una posicion
          }
          //Comparacion de sincronia entre los valores constantes de la trama
          if (trama[0] == 0x20 & trama[1] == 0x40 & trama[28] == 0xDC & trama[29] == 0x05)wait = 0;//Bandera de espera en 0 indica que se termino la sincronizacion
        }
      }
    }

    //Cargado de los valores reales de los canales
    //Canal(16bits) = MBS(8bits) + LBS(8bits)
    channel[0] = (trama[3] << 8) + trama[2]; //channel 1
    channel[1] = (trama[5] << 8) + trama[4];
    channel[2] = (trama[7] << 8) + trama[6];
    channel[3] = (trama[9] << 8) + trama[8];
    channel[4] = (trama[11] << 8) + trama[10];
    channel[5] = (trama[13] << 8) + trama[12];
    channel[6] = (trama[15] << 8) + trama[14];
    channel[7] = (trama[17] << 8) + trama[16];
    channel[8] = (trama[19] << 8) + trama[18];
    channel[9] = (trama[21] << 8) + trama[20];

    //Conversion de los valores de los canales en posiciones angulares
    int pos1 = map(channel[0], 1000, 2000, _minAngle, _maxAngle);
    int pos2 = map(channel[1], 1000, 2000, _minAngle, _maxAngle);
    int pos3 = map(channel[2], 1000, 2000, _minAngle, _maxAngle);
    int pos4 = map(channel[3], 1000, 2000, _minAngle, _maxAngle);
    int pos5 = map(channel[4], 1000, 2000, _minAngle, _maxAngle);
    int pos6 = map(channel[5], 1000, 2000, _minAngle, _maxAngle);
    int pos7 = map(channel[6], 1000, 2000, _minAngle, _maxAngle);
    int pos8 = map(channel[7], 1000, 2000, _minAngle, _maxAngle);
    int pos9 = map(channel[8], 1000, 2000, _minAngle, _maxAngle);
    int pos10 = map(channel[9], 1000, 2000, _minAngle, _maxAngle);

    //Declaracion de los pines a usar como salida para los servos
    servo1.attach(this->_port1);
    servo2.attach(this->_port2);
    servo3.attach(this->_port3);
    servo4.attach(this->_port4);
    servo5.attach(this->_port5);
    servo6.attach(this->_port6);
    servo7.attach(this->_port7);
    servo8.attach(this->_port8);
    servo9.attach(this->_port9);
    servo10.attach(this->_port10);

    //Actualizacion de lo los valores de cada PWM
    servo1.write(pos1);
    servo2.write(pos2);
    servo3.write(pos3);
    servo4.write(pos4);
    servo5.write(pos5);
    servo6.write(pos6);
    servo7.write(pos7);
    servo8.write(pos8);
    servo9.write(pos9);
    servo10.write(pos10);
  } 
}


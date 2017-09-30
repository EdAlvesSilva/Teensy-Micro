/* Codigo feito por Eduardo Alves da Silva
 *  
 *  Integrante da Equipe Minerva Rockets - UFRJ
 */

 
#include <SD.h> //Necessaria para escrever no cartao SD
#include <SPI.h> //Necessaria para o arduino se comunicar com o Cartao SD
#define PINO_MICROFONE  0 //Pino onde o microfone sera ligado
File myFile; //Arquivo csv onde os dados do microfone serao escritos



/* [MINERVA ROCKETS] Basicamente, essa linha escolhe qual vai ser 
 *  o pino de CS usado para o Cartao SD, seja ele em um modulo, ou 
 *  um cartao SD feito ja na placa (caso do Teensy por exemplo)
 *  As instruções abaixo especificam qual deve ser o CS usado no
 *  codigo, dependendo do modulo/microcontrolador que vc esteja usando
 */
// change this to match your SD shield or module;
// Arduino Ethernet shield: pin 4
// [COBRUF 2017] USAR ESSE AQUI : Adafruit SD shields and modules: pin 10
// Sparkfun SD shield: pin 8
// Teensy audio board: pin 10
// Teensy 3.5 & 3.6 on-board: BUILTIN_SDCARD
// Wiz820+SD board: pin 4
// Teensy 2.0: pin 0
// Teensy++ 2.0: pin 20
const int chipSelect = 10;

void setup()
{
  // Inicia o modulo do cartao SD
    SD.begin(chipSelect);
}

File csvfile;
int val;
int tempo;


void loop()                     
{
  //Abre o arquivo "Micro.csv", para escrever is dados do microfone
  csvfile = SD.open("Micro.csv",FILE_WRITE);

  //Faz uma amostragem do microfone, que se encontra no pino digital A0
  val = analogRead(PINO_MICROFONE);
 //Verifica o tempo, em microsegundos (desde que o Arduino foi
 // inicializado), em que foi feita a amostragem
  tempo = micros();
  //Escreve no Arquivo csv da seguinte forma : 
  // Valor_Microfone,Tempo[Enter]
  csvfile.print(val);
  csvfile.print(",");
  csvfile.println(tempo);

  //Fecha o Arquivo antes de reiniciar um novo loop
  csvfile.close();
}



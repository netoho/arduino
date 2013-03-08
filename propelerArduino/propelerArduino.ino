#include <EEPROM.h>

const int NP = 6;
const int M = 240;
const int pinInterrupt = 0;
volatile int idM = 0;
byte leds[M][NP];
double io = 0;

void setup(){
  Serial.begin(9600);
  attachInterrupt(pinInterrupt, interrupt, RISING);
  DDRC = B11111111;
  DDRA = B11111111;
  DDRK = B11111111;
  DDRB = B11111111;
  DDRL = B11111111;
  DDRF = B11111111;
  
  for(int m = 0; m < M; m++)
    for(int np = 0; np < NP; np++)
      leds[m][np] = m;
}

void loop(){
  if(Serial.available()){
    for(int m = 0; m < M; m++)
      for(int np = 0; np < NP; np++){
        leds[m][np] = Serial.read();
        delay(15);
      }
  }
  turnOnLeds(leds[idM]);
//  interrupt();
//  delay(50);
}

void interrupt(){
    if(idM == M-1) idM = 0;
    else idM++;
}

void turnOnLeds(byte value[]){
  PORTC = value[0];
  PORTA = value[1];
  PORTK = value[2];
  PORTB = value[3];
  PORTL = value[4];
  PORTF = value[5];
}

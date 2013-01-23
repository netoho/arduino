const int EA = 2;
const int NP = 3;
const int M = 200;
const int pinControl = 51;
volatile int dt = 0;
volatile int idM = 0;
byte leds[M][EA][NP];

void setup(){
  Serial.begin(9600);
  dt = micros();
  attachInterrupt(20, interrupt, RISING);
  DDRA = B11111111
  DDRC = B11111111
  DDRL = B11111111
}

void loop(){
  if(Serial.available() > 10){
    for(int m = 0; m < M; m++)
      for(int np = 0; np < NP; np++)
        for(int ea = 0; ea < EA; ea++)
          leds[m][ea][np] = Serial.read();
  }
  for(int np = 0; np < 3; np++){
    turnOnLeds(leds[idM][0][np], np, 0);
  }
  delayMicroseconds(dt/2);
  for(int np = 0; np < 3; np++){
    turnOnLeds(leds[idM][1][np], np, 1);
  }
  delayMicroseconds(dt/2);
}

void interrupt(){
  dt = micros() - dt;
  if(idM == M-1) idM = 0;
  else idM++;
}

void turnOnLeds(byte value, int np, int ea){
  if(ea == 0){
    digitalWrite(pinControl, LOW);
    turnOnLed(value, np);
  }else{
    digitalWrite(pinControl, HIGH);
    turnOnLed(value, np);
  }
}

void turnOnLed(byte value, int np){
  switch(np){
      case 0:
        PORTL = value
      break;
      case 1:
        PORTC = value
      break;
      case 2:
        PORTA = value
      break;
  }
}

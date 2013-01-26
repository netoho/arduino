const int EA = 2;
const int NP = 3;
const int M = 2;
const int pinControl = 51;
volatile int dt = 0;
volatile int idM = 0;
byte leds[M][EA][NP];
double io = 0;

void setup(){
  Serial.begin(115200);
  pinMode(pinControl, OUTPUT);
  dt = micros();
  attachInterrupt(20, interrupt, RISING);
  DDRA = B11111111;
  DDRC = B11111111;
  DDRL = B11111111;
  for(int m = 0; m < M; m++)
    for(int np = 0; np < NP; np++)
      for(int ea = 0; ea < EA; ea++)
        leds[m][ea][np] = 0;
}

void loop(){
  if(Serial.available()){
    for(int m = 0; m < M; m++)
      for(int np = 0; np < NP; np++)
        for(int ea = 0; ea < EA; ea++){
          leds[m][ea][np] = Serial.read();
          delay(3);
        }
  }
  turnOnLeds(leds[idM][0], 1);
//  delay(500);
  delayMicroseconds(dt/2);
  turnOnLeds(leds[idM][1], 0);
//  delay(500);
  delayMicroseconds(dt/2);
  interrupt();
}

void interrupt(){
  dt = micros() - dt;
    if(idM == M-1) idM = 0;
    else idM++;
}

void turnOnLeds(byte value[], int ea){
    digitalWrite(pinControl, ea);
    turnOnLed(value);
}

void turnOnLed(byte value[]){
  PORTL = value[0];
  PORTC = value[1];
  PORTA = value[2];
}

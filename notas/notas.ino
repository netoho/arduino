byte note = 0; //The MIDI note value to be played
byte resetMIDI = 4; //Tied to VS1053 Reset line
byte ledPin = 13; //MIDI traffic inidicator

int InputA = 12;
int InputB = 11;
//nuevos electrodos
int InputC = 10;
int InputD = 9;
int InputE = 8;
int InputF = 7;
int InputG = 6;
int InputH = 5;
//
int instrument = 33;
int timeOn = 100;
int timeOff = 50;
int timeInstruments = 100;
int notas = 0;

void setup() {
  Serial.begin(9600);
 
  pinMode(InputA, INPUT);
  pinMode(InputB, INPUT);
  pinMode(InputC, INPUT);
  pinMode(InputD, INPUT);
  pinMode(InputE, INPUT);
  pinMode(InputF, INPUT);
  pinMode(InputG, INPUT);
  pinMode(InputH, INPUT);
}

void loop() {
  delay(10);
  notas = 0;
    if(digitalRead(InputA) == HIGH){
      notas += 1;
    } 
    if(digitalRead(InputB) == HIGH){
      notas +=2;
    }
    if(digitalRead(InputC) == HIGH){
      notas+=4;
    }
    if(digitalRead(InputD) == HIGH){
      notas += 8;
    }
    if(digitalRead(InputE) == HIGH){
      notas += 16;
    }
    if(digitalRead(InputF) == HIGH){
      notas += 32;
    }
    if(digitalRead(InputG) == HIGH){
      notas += 64;
    }
    if(digitalRead(InputH) == HIGH){
      notas +=128;
    } 
    Serial.write(notas);     
}

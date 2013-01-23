int InputA = 5;
int InputB = 6;
int InputC = 7;
int InputD = 8;
int InputE = 9;
int InputF = 10;
int InputG = 11;
int InputH = 12;

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
  delay(20);
  notas = 0;
    if(digitalRead(InputA)){
      notas += 1;
    } 
    if(digitalRead(InputB)){
      notas +=2;
    }
    if(digitalRead(InputC)){
      notas += 4;
    }
    if(digitalRead(InputD)){
      notas += 8;
    }
    if(digitalRead(InputE)){
      notas += 16;
    }
    if(digitalRead(InputF)){
      notas += 32;
    }
    if(digitalRead(InputG)){
      notas += 64;
    }
    if(digitalRead(InputH)){
      notas += 128;
    } 
    Serial.write(notas);     
}

int InputA = 2;
int InputB = 3;
int InputC = 4;
int InputD = 5;
int InputE = 6;
int InputF = 7;
int InputG = 12;
int InputH = 13;

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

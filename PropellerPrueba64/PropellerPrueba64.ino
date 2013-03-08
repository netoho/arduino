
// Programa para recibir e imprimir datos con el propeller
// Desarrollado por tu papa.

int var = 255;
int pin = 13;
volatile int state = LOW;

void setup(){
       //B12345678
  DDRA = B11111111;
  DDRC = B11111111;
  DDRL = B11111111;
  DDRB = B11111111;
  DDRK = B11111111;
  DDRF = B11111111;
  //pinMode(pin, OUTPUT);
  //attachInterrupt(0, blink, CHANGE);
  Serial.begin(115200);
  //digitalWrite(LedControl, HIGH);
}


void loop(){
  for (int i = 0; i < 256; i ++){
    var = i;
    PORTA = byte(var);
    PORTC = byte(var);
    PORTL = byte(var);
    PORTB = byte(var);
    PORTK = byte(var);
    PORTF = byte(var);
    delay(100);
  }
  //digitalWrite(pin, state);
}

void blink(){
  state = !state;
}


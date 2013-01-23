
int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte

void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  if(Serial.available() > 0){
    Serial.read();
    digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }
  inByte = map(analogRead(A0),0,1024,0,255);
  Serial.println(inByte);
  delay(50);
}

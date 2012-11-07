
int firstSensor = 0;    // first analog sensor
int secondSensor = 0;   // second analog sensor
int thirdSensor = 0;    // digital sensor
int inByte = 0;         // incoming serial byte

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  if(Serial.available() > 0){
    int a = Serial.read();
    if(a == 65)
      digitalWrite(13, HIGH);
    if(a == 66)
      digitalWrite(13, LOW);
  }
}

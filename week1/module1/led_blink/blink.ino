/*
Author : Shahanas S
Roll No : 68

Description :
Basic LED Blink
*/
int potValue;
int blinkDelay;
void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  potValue = analogRead(A0);

  blinkDelay = map(potValue,0,1023,100,1000);

  digitalWrite(13,HIGH);
  Serial.println("LED ON");
  delay(blinkDelay);

  digitalWrite(13,LOW);
  Serial.println("LED OFF");
  delay(blinkDelay);
}


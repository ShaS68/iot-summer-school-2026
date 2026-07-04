/*
Author : Shahanas S
Roll No : 68

Description :
Basic LED Blink
*/

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(13, HIGH);
  Serial.println("LED ON");
  delay(500);

  digitalWrite(13, LOW);
  Serial.println("LED OFF");
  delay(500);
}


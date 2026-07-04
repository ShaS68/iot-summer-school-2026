/*
Author : Shahanas S
Roll No : 68

Description :
Basic LED Blink
*/

void setup()
{
  pinMode(13, OUTPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(500);

  digitalWrite(13, LOW);
  delay(500);
}

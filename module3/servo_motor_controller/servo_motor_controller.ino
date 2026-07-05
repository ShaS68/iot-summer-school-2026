#include <Servo.h>

Servo myServo;

const int potPin = A0;
const int ledPin = 7;

void setup()
{
  myServo.attach(9);

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  int potValue = analogRead(potPin);

  int angle = map(potValue, 0, 1023, 0, 180);

  myServo.write(angle);

  Serial.print("Servo Angle: ");
  Serial.println(angle);

  if(angle > 150)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }

  delay(200);
}

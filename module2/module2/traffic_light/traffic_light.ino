const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int buttonPin = 7;

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(buttonPin) == LOW)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    Serial.print(millis());
    Serial.println(" ms : Pedestrian Crossing");

    delay(5000);
    return;
  }

  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);

  Serial.print(millis());
  Serial.println(" ms : RED");

  delay(5000);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);

  Serial.print(millis());
  Serial.println(" ms : YELLOW");

  delay(2000);

  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);

  Serial.print(millis());
  Serial.println(" ms : GREEN");

  delay(4000);

  digitalWrite(greenLED, LOW);
}

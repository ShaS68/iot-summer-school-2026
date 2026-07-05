const int ledPin = 9;
const int buttonPin = 2;

int mode = 0;
bool lastButtonState = HIGH;

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode: Slow Breathing");
}

void loop()
{
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH)
  {
    mode++;

    if (mode > 2)
      mode = 0;

    if (mode == 0)
      Serial.println("Mode: Slow Breathing");

    if (mode == 1)
      Serial.println("Mode: Fast Pulse");

    if (mode == 2)
      Serial.println("Mode: SOS");

    delay(200);
  }

  lastButtonState = buttonState;

  if (mode == 0)
    slowBreathing();

  else if (mode == 1)
    fastPulse();

  else
    sosPattern();
}

void slowBreathing()
{
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(ledPin, i);
    delay(2);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite(ledPin, i);
    delay(2);
  }
}

void fastPulse()
{
  for (int i = 0; i <= 255; i++)
  {
    analogWrite(ledPin, i);
    delay(1);
  }

  for (int i = 255; i >= 0; i--)
  {
    analogWrite(ledPin, i);
    delay(1);
  }
}

void sosPattern()
{
  dot();
  dot();
  dot();

  dash();
  dash();
  dash();

  dot();
  dot();
  dot();

  delay(1000);
}

void dot()
{
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(ledPin, LOW);
  delay(200);
}

void dash()
{
  digitalWrite(ledPin, HIGH);
  delay(600);
  digitalWrite(ledPin, LOW);
  delay(200);
}

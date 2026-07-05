const int potPin = A0;
const int motorPin = 9;
const int greenLED = 7;
const int redLED = 8;

void setup() {

  pinMode(motorPin, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Serial.begin(9600);

}

void loop() {

  int potValue = analogRead(potPin);

  int pwmValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(motorPin, pwmValue);

  Serial.print("PWM Value: ");
  Serial.println(pwmValue);

  if (pwmValue > 191) {

    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);

  }

  else if (pwmValue < 64) {

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);

  }

  else {

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);

  }

  delay(200);

}

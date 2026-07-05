const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;

const int threshold = 500;

unsigned long motionTime = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  int light = analogRead(ldrPin);
  int motion = digitalRead(pirPin);

  if (light > threshold) {
    analogWrite(ledPin, 0);
    Serial.println("Daytime - LED OFF");
  }

  else {

    if (motion == HIGH) {

      analogWrite(ledPin, 255);

      motionTime = millis();

      Serial.println("Motion Detected - LED FULL BRIGHTNESS");
    }

    else {

      if (millis() - motionTime < 30000) {

        analogWrite(ledPin, 255);

      }

      else {

        analogWrite(ledPin, 51);

        Serial.println("No Motion - LED DIM");

      }

    }

  }

  delay(500);

}

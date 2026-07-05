const int onButton = 2;
const int offButton = 3;
const int appliance = 8;

void setup() {

  pinMode(onButton, INPUT_PULLUP);
  pinMode(offButton, INPUT_PULLUP);

  pinMode(appliance, OUTPUT);

  digitalWrite(appliance, LOW);

  Serial.begin(9600);

  Serial.println("AC Appliance Control System");

}

void loop() {

  if (digitalRead(onButton) == LOW) {

    digitalWrite(appliance, HIGH);

    Serial.println("Appliance ON");

    delay(300);

  }

  if (digitalRead(offButton) == LOW) {

    digitalWrite(appliance, LOW);

    Serial.println("Appliance OFF");

    delay(300);

  }

}

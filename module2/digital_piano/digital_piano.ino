const int buzzer = 8;

const int doBtn = 2;
const int reBtn = 3;
const int miBtn = 4;
const int faBtn = 5;
const int modeBtn = 6;

bool majorMode = true;

void setup()
{
  pinMode(doBtn, INPUT_PULLUP);
  pinMode(reBtn, INPUT_PULLUP);
  pinMode(miBtn, INPUT_PULLUP);
  pinMode(faBtn, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(modeBtn) == LOW)
  {
    majorMode = !majorMode;

    if (majorMode)
      Serial.println("Major Mode");
    else
      Serial.println("Minor Mode");

    delay(300);
  }

  bool d = digitalRead(doBtn) == LOW;
  bool r = digitalRead(reBtn) == LOW;
  bool m = digitalRead(miBtn) == LOW;
  bool f = digitalRead(faBtn) == LOW;

  if ((d && r) || (d && m) || (d && f) || (r && m) || (r && f) || (m && f))
  {
    tone(buzzer, 392);
    Serial.println("Sol");
  }
  else if (d)
  {
    tone(buzzer, 262);
    Serial.println("Do");
  }
  else if (r)
  {
    tone(buzzer, 294);
    Serial.println("Re");
  }
  else if (m)
  {
    if (majorMode)
      tone(buzzer, 330);
    else
      tone(buzzer, 311);

    Serial.println("Mi");
  }
  else if (f)
  {
    if (majorMode)
      tone(buzzer, 349);
    else
      tone(buzzer, 330);

    Serial.println("Fa");
  }
  else
  {
    noTone(buzzer);
  }
}

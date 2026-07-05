const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

int state = 0;

// 0 = IDLE
// 1 = COIN_INSERTED
// 2 = ITEM_SELECTED
// 3 = DISPENSING

void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  Serial.begin(9600);

  Serial.println("State : IDLE");
}

void loop()
{
  if(state == 0)
  {
    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    if(digitalRead(coinBtn) == LOW)
    {
      state = 1;
      Serial.println("IDLE -> COIN_INSERTED");
      delay(300);
    }
  }

  else if(state == 1)
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, HIGH);
    digitalWrite(greenLED, LOW);

    if(digitalRead(selectBtn) == LOW)
    {
      state = 2;
      Serial.println("COIN_INSERTED -> ITEM_SELECTED");
      delay(300);
    }

    if(digitalRead(cancelBtn) == LOW)
    {
      state = 0;
      Serial.println("Transaction Cancelled");
      delay(300);
    }
  }

  else if(state == 2)
  {
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, HIGH);

    Serial.println("ITEM_SELECTED -> DISPENSING");

    state = 3;

    delay(1000);
  }

  else if(state == 3)
  {
    Serial.println("DISPENSING -> IDLE");

    digitalWrite(redLED, HIGH);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);

    state = 0;

    delay(1000);
  }
}

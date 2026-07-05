String command;
int blinkCount = 0;

void setup()
{
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  Serial.println("Enter Command:");
}

void loop()
{
  if (Serial.available())
  {
    command = Serial.readStringUntil('\n');
    command.trim();

    if (command == "LED_ON")
    {
      digitalWrite(13, HIGH);
      Serial.println("LED ON");
    }

    else if (command == "LED_OFF")
    {
      digitalWrite(13, LOW);
      Serial.println("LED OFF");
    }

    else if (command == "BLINK")
    {
      for (int i = 0; i < 5; i++)
      {
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
      }

      blinkCount++;
      Serial.println("Blink Completed");
    }

    else if (command == "STATUS")
    {
      Serial.print("LED Status: ");

      if (digitalRead(13))
        Serial.println("ON");
      else
        Serial.println("OFF");

      Serial.print("Blink Count: ");
      Serial.println(blinkCount);
    }

    else if (command == "RESET")
    {
      blinkCount = 0;
      Serial.println("Blink Counter Reset");
    }

    else
    {
      Serial.println("ERROR: Unknown command");
    }
  }
}

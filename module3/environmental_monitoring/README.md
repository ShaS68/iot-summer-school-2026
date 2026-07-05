#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int redLED = 8;

void setup()
{
  Serial.begin(9600);

  dht.begin();

  pinMode(redLED, OUTPUT);

  Serial.println("Time(ms),Temp_C,Temp_F,Humidity");
}

void loop()
{
  float humidity = dht.readHumidity();

  float tempC = dht.readTemperature();

  float tempF = dht.readTemperature(true);

  if (isnan(humidity) || isnan(tempC))
  {
    Serial.println("Sensor Error");
    return;
  }

  Serial.print(millis());
  Serial.print(",");

  Serial.print(tempC);
  Serial.print(",");

  Serial.print(tempF);
  Serial.print(",");

  Serial.println(humidity);

  if (tempC > 35 || humidity > 80)
  {
    digitalWrite(redLED, HIGH);
  }
  else
  {
    digitalWrite(redLED, LOW);
  }

  delay(2000);
}

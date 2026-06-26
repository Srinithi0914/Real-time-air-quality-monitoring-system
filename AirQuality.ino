#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define MQ135_PIN 34

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  int airQuality = analogRead(MQ135_PIN);

  Serial.println("---------------------");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Air Quality Value: ");
  Serial.println(airQuality);

  if (airQuality < 1000)
    Serial.println("Air Quality: GOOD");
  else if (airQuality < 2000)
    Serial.println("Air Quality: MODERATE");
  else
    Serial.println("Air Quality: POOR");

  delay(2000);
}

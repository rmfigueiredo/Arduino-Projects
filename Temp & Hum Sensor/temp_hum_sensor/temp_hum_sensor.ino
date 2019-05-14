/**
 * Author: Rodrigo Figueiredo
 *     rodrigofigueiredo@tecnico.ulisboa.pt
 * Last change: 12/03/2019 
 * 
 */

#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

char auth[] = "9062029bd98c41c89355e4817dd81975";

char ssid[] = "CandyMachine";
char pass[] = "abcd1234";

const int MaxTemp = 20;
const int MaxHum = 50;

#define DHTPIN 2          // What digital pin we're connected to

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11

DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
WidgetLED ledt(V0);
WidgetLED ledh(V1);

// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.

void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V5, h);
  Blynk.virtualWrite(V6, t);
  Serial.printf("Temperature: %f\n", t);
  Serial.printf("Humidity: %f\n", h);
  if(h > MaxHum)
    ledt.on();
  else
    ledt.off();

  if(t > MaxTemp)
    ledh.on();
  else
    ledh.off();
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);

  dht.begin();

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}

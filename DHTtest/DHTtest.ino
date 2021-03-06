// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// uses DHT-sensor-library
// https://github.com/adafruit/DHT-sensor-library

// modified by fuzzyleapfrog for first experiments with DHT11

#include "DHT.h"

#define DHTPIN 2     // what pin we're connected to

// Uncomment whatever type you're using
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.print("DHT");
  Serial.print(DHTTYPE);
  Serial.println(" test!");

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Read relative humidity in percent
  float h = dht.readHumidity();
  // Read temperature in degree Celsius
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute saturation vapor pressure
  // https://en.wikipedia.org/wiki/Clausius-Clapeyron_relation
  float es = 6.1094*exp(17.625*t/(243.04+t));
  // Compute vapor pressure
  // https://en.wikipedia.org/wiki/Humidity#Relative_humidity
  float e = t*h/100.;
  // Compute absolute humidity
  // https://en.wikipedia.org/wiki/Humidity#Absolute_humidity
  // http://planetcalc.com/2167/
  float ah = (e*100)/(461.52*(t+273.15))*1000.;

  Serial.print("Measurement ::\t");
  Serial.print("Relative Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");

  Serial.print("Calculation ::\t");
  Serial.print("Saturation Vapor pressure: ");
  Serial.print(es);
  Serial.print(" hPa\t");
  Serial.print("Vapor pressure: ");
  Serial.print(e);
  Serial.print(" hPa\t");
  Serial.print("Absolute himidity: ");
  Serial.print(ah);
  Serial.println(" g/m^3");
}

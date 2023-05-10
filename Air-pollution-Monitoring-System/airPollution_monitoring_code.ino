//Libraries
#include <ESP8266WiFi.h>
#include <DHT.h>
#define DHTTYPE DHT11  // DHT11 sensor type
#include "ThingSpeak.h"

//Assign pin number to respective sensors analog/digital pins
#define DHTPIN 0       
#define MQ135_PIN A0   

DHT dht(DHTPIN, DHTTYPE);

unsigned long channel = 2141773;               //ThingSpeak channel ID
const char * myWriteAPIKey = "2YIKSQOUYOIB06DW";  //ThingSpeak WriteAPI Key

WiFiClient client;

//Code for setup - check wifi connection
void setup() {
  Serial.begin(9600);
  WiFi.begin("motorola one fusion+ 2928", "e226957c0583");  // Replace with your SSID and password
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  Serial.println("Connected to WiFi");
  Serial.println("IP address is : ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);                // initializes the connection and allows the client to start sending data to the server.
  Serial.println("Server started");
  dht.begin();
}

void loop() {
  //create variable for respective values which sensor will sends
  float temperature = dht.readTemperature();          //for temperature
  float humidity = dht.readHumidity();                //for humidity

  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT11 sensor");
    return;
  }

  float air_quality = analogRead(MQ135_PIN);                  //for air quality

  //Print the values on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Air Quality: ");  
  Serial.println(air_quality);
  delay(5000);

  //Connect to ThingSpeak
  //Write three fields in thingSpeak
  ThingSpeak.setField(1,temperature);
  ThingSpeak.setField(2,humidity);
  ThingSpeak.setField(3,air_quality);

  ThingSpeak.writeFields(channel, myWriteAPIKey);
}

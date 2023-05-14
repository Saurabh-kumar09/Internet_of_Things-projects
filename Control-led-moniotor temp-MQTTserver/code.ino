#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define LED 16

const char* ssid = "motorola one fusion+ 2928";
const char* password =  "e226957c0583";
const char* mqtt_server = "91.121.93.94";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);
void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(5,INPUT_PULLUP);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.print("Connected to WiFi :");
  Serial.println(WiFi.SSID());
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(MQTTcallback);
  while (!client.connected()) 
  {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP8266"))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed with state ");
      Serial.println(client.state());
      delay(2000);
    }
  }
  client.subscribe("esp/test");
}
void MQTTcallback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message received in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  String message;
  for (int i = 0; i < length; i++) 
  {
    message = message + (char)payload[i];
  }
  Serial.print(message);
  if (message == "on") 
  {
    digitalWrite(LED, HIGH);
  }
  else if (message == "off") 
  {
    digitalWrite(LED, LOW);
  }
  Serial.println();
  Serial.println("-----------------------");
}
void loop() 
{
  if(digitalRead(5)==0)
  {
  client.publish("esp/test1", "Hello from ESP8266");
  delay(1000);
  }
  else;
  client.loop();
}

//Code for Smart Dustbin

#include<ESP8266WiFi.h>               //ESP8266 libraray
#include "ThingSpeak.h"               //ThingSpeak library
#include <Servo.h>                    //ServoMotor library
Servo servoMain; // Define our Servo

//Define the pin configuration

//For outer Ultrasonic sensor
int trigpin_out = 12;  //d6
int echopin_out = 14; //d5
int distance;
float duration;

//For inner ultrasonic sensor
int trigpin_in = 5;
int echopin_in = 4;
int distance_bin;
float duration_bin;
int level;

//Connect your wifi
const char* ssid = "motorola one fusion+ 2928";
const char* password = "e226957c0583";

unsigned long channel = 2131704;               //ThingSpeak channel ID
const char * myWriteAPIKey = "PN49N1DPLLAYNWK9";  //ThingSpeak WriteAPI Key

WiFiClient client;

//Code for setup - Assign the pin as output/Input and check wifi connection
void setup()
{
   servoMain.attach(16); // servo on digital pin D0
    pinMode(trigpin_out, OUTPUT);
    pinMode(echopin_out, INPUT);
    pinMode(trigpin_in, OUTPUT);
    pinMode(echopin_in, INPUT);
    Serial.begin(9600);
    Serial.print("Connecting to Wifi Network");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    }
Serial.println("");
Serial.println("Successfully connected to WiFi.");
Serial.println("IP address is : ");
Serial.println(WiFi.localIP());
ThingSpeak.begin(client);                   // initializes the connection and allows the client to start sending data to the server.
Serial.println("Server started");

}

void loop()
{ 
  
  //For OUTER Ultrasonic sensor
  digitalWrite(trigpin_out, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigpin_out, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigpin_out, LOW);  
  duration = pulseIn(echopin_out, HIGH);  
  distance = 0.034* (duration/2);
  //Serial.println(distance);
  
  if(distance<30)
  {
    servoMain.write(0);  // Turn Servo back to center position (90 degrees)
    Serial.println("Distance");
    Serial.println(distance);
   delay(1000); 
  }
   else{
     servoMain.write(180);
     delay(3000);
   }

   //For INNER Ultrasonic sensor
   digitalWrite(trigpin_in, LOW);
  delayMicroseconds(2);  
  digitalWrite(trigpin_in, HIGH);
  delayMicroseconds(10);  
  digitalWrite(trigpin_in, LOW);  
  duration_bin = pulseIn(echopin_in, HIGH);  

  //Calculate the distance of waste from inner ultrasonic sensor
  distance_bin = 0.034 * (duration_bin/2);
  Serial.println("Distance_bin:");
  Serial.println(distance_bin);

  //Calculate the level of waste in dustbin
  level =((26 - distance_bin)/26.0)*100;
  Serial.println("level");
  Serial.println(level);

  //Connect to ThingSpeak
  //Write three fields in thingSpeak
  ThingSpeak.setField(1,distance);
  ThingSpeak.setField(2,distance_bin);
  ThingSpeak.setField(3,level);

  ThingSpeak.writeFields(channel, myWriteAPIKey);
  
}

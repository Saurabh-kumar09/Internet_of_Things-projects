#include <ESP8266WiFi.h>
#define echo 14
#define trig 0

#define LED1 16
#define LED2 5
#define LED3 4


float  duration;
float  distance;

void setup() {

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  for (int i = 1; i <= 7; i++)
    pinMode(i, OUTPUT);


  Serial.begin(9600);

}

void loop() {

  time_Measurement();
  distance = duration * (0.0343) / 2;
  Serial.println(distance);

  led_Check();
  delay(10);

  for (int i = LED1; i <= LED3; i++) {
    digitalWrite(i, LOW);
  }
}


void time_Measurement()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
}

void led_Check() {
  
  if (6 < distance && distance <= 7)
    digitalWrite(LED3, HIGH);
  else if (5 < distance && distance <= 6)
    digitalWrite(LED2, HIGH);
  else if (1 < distance && distance <= 5)
    digitalWrite(LED1, HIGH);

  else {
    for (int i = LED1; i <= LED3; i++)
      digitalWrite(i, LOW);
  }

}

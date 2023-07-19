#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// Replace with your network credentials
const char* ssid = "YOUR SSIS";
const char* password = "****";

// Replace with your Firebase project details
const char* firebaseHost = "*****";
const char* firebaseAuth = "*****";

// Firebase database path
const String databasePath = "/analogValue";

// Pin connected to the potentiometer
const int analogPin = A0;

// Initialize Firebase
FirebaseData firebaseData;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Firebase
  Firebase.begin(firebaseHost, firebaseAuth);

  // Wait for Firebase to initialize
  while (!Firebase.ready()) {
    delay(100);
  }
  Serial.println("Connected to Firebase");
}

void loop() {
  // Read the analog value from the potentiometer
  int analogValue = map(analogRead(analogPin),0,1023,0,255);
  // Print the analog value to the Serial Monitor
  Serial.println("Analog value: " + String(analogValue));

  // Store the analog value in Firebase only if it is greater than 100
  if (analogValue > 100) {
    if (Firebase.setInt(firebaseData, databasePath, analogValue)) {
      Serial.println("Analog value stored in Firebase: " + String(analogValue));
    } else {
      Serial.println("Error storing analog value in Firebase: " + firebaseData.errorReason());
    }
  }

  // Wait for some time before taking the next reading
  delay(1000);
}

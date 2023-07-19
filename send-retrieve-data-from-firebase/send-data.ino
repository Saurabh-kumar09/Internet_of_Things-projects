#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

// Replace with your network credentials
const char* ssid = "YOUR SSID";
const char* password = "*****";

// Replace with your Firebase project details
const char* firebaseHost = "*****";
const char* firebaseAuth = "*****";


 static int a = 1;  
 static int b = 5;
 static int c = 10;

// Initialize Firebase
FirebaseData firebaseData;


void setup() {
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
  a = a + 1;
  b = b + 5;
  c = c + 10;

 
  if (a > 30,b>150,c>300) {
    a = 1;
    b = 5;
    c = 10;  
  }
  Serial.println("a:"+String(a));
  Serial.println("b:"+String(b));
  Serial.println("c:"+String(c));

  Firebase.setInt(firebaseData, "/variables/a", a);
  Firebase.setInt(firebaseData, "/variables/b", b);
  Firebase.setInt(firebaseData, "/variables/c", c);

  if (firebaseData.httpCode() == 200) {
    Serial.println("Data sent to Firebase successfully");
  } else {
    Serial.println("Error sending data to Firebase");
    Serial.println(firebaseData.errorReason());
  }

  delay(1000);  
}

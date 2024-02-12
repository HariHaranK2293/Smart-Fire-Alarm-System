#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char ssid[] = "iqoo7";
char pass[] = "Hariharan2293";

// Blynk authentication token
char auth[] = "YourBlynkAuthToken";


int fireSensorPin = D1; 

void setup() {
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize Blynk
  Blynk.begin(auth, ssid, pass);

  // Initialize fire sensor pin
  pinMode(fireSensorPin, INPUT);
}

void loop() {
  Blynk.run();

  // Read fire sensor
  int fireDetected = digitalRead(fireSensorPin);

  // If fire is detected, send notification
  if (fireDetected == HIGH) {
    Serial.println("Fire detected");
    Blynk.notify("Fire detected");
    delay(5000); 
  }

  delay(1000); // Delay for stability
}


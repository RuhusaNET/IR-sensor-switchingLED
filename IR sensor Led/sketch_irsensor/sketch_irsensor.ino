// IR Sensor
// Author: Ruhusa
// Description: Turns ON an LED when an object is detected

// Pin definitions
const int irSensorPin = 2;   // IR sensor OUT pin connected to D2
const int ledPin = 9;       // LED connected to D13

void setup() {
  // Set pin modes
  pinMode(irSensorPin, INPUT);   // IR sensor gives input to Arduino
  pinMode(ledPin, OUTPUT);       // LED is an output

  // Start serial communication
  Serial.begin(9600);
  Serial.println("IR Sensor Test Started");
  //digitalWrite(RELAY_PIN, HIGH);  // Relay OFF at startup
}

void loop() {
  // Read IR sensor value
  int sensorValue = digitalRead(irSensorPin);

  // Most IR sensors output LOW when object is detected
  if (sensorValue == LOW) {
    digitalWrite(ledPin, HIGH);     // Turn ON LED
    Serial.println("Object Detected");
  } else {
    digitalWrite(ledPin, LOW);      // Turn OFF LED
    Serial.println("No Object");
  }
 
  delay(500); // Small delay for stability
}

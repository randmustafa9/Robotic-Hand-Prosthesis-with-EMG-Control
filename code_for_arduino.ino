#include <Servo.h>

// Define pins
const int emgPin = A0;  // EMG sensor output (Tip) connected to analog pin A0
const int servoPin1 = 9; // First servo motor connected to digital pin 9
const int servoPin2 = 12; // Second servo motor connected to digital pin 10

// Threshold for muscle contraction detection
const int threshold = 500; // Adjust based on your EMG sensor output

Servo servoMotor1;
Servo servoMotor2;

void setup() {
  pinMode(emgPin, INPUT);
  servoMotor1.attach(servoPin1);
  servoMotor2.attach(servoPin2);

  // Initialize both servos
  servoMotor1.write(0);  // Start with servo 1 in open position
  servoMotor2.write(0); // Start with servo 2 in closed position (opposite)
  Serial.begin(9600);    // For debugging and sensor calibration
}

void loop() {
  int emgValue = analogRead(emgPin);
  Serial.println(emgValue); // Monitor EMG sensor values

  if (emgValue > threshold) {
    // Muscle contracted
    servoMotor1.write(180); // Close fingers (servo 1)
    servoMotor2.write(180);   // Open fingers (servo 2, opposite movement)
  } else {
    // Muscle relaxed
    servoMotor1.write(0);   // Open fingers (servo 1)
    servoMotor2.write(0); // Close fingers (servo 2, opposite movement)
  }

  delay(200); // Small delay to stabilize readings
}

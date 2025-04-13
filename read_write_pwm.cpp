#include <Arduino.h>

const int receiverPin = PA0;  // Signal from receiver
const int outputPin = PA8;    // Output PWM to device

void setup() {
  Serial.begin(9600);         
  pinMode(receiverPin, INPUT);
  pinMode(outputPin, OUTPUT);
}

void loop() {
  unsigned long highTime = pulseIn(receiverPin, HIGH);
  unsigned long period = pulseIn(receiverPin, HIGH) + pulseIn(receiverPin, LOW);
  
  if (period > 0) {
    int dutyCycle = (highTime * 255) / period;
    analogWrite(outputPin, dutyCycle);
    
    Serial.print("Duty: ");
    Serial.println(dutyCycle);
  }
}

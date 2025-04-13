#include <Arduino.h>

HardwareSerial ReceiverSerial(2); // USART2 (PA2 = RX)

const int channel1OutputPin = PA15; // PWM output 1
const int channel2OutputPin = PB10; // PWM output 2

void setup() {
  Serial.begin(9600);            
  ReceiverSerial.begin(420000);  // ELRS Crossfire baud rate
  
  pinMode(channel1OutputPin, OUTPUT);
  pinMode(channel2OutputPin, OUTPUT);
}

void loop() {
  static uint8_t buffer[64];
  static int bufferIndex = 0;

  while (ReceiverSerial.available()) {
    uint8_t byte = ReceiverSerial.read();
    buffer[bufferIndex++] = byte;

    if (bufferIndex >= expectedPacketSize) { // Expected full packet
      // Parse channels
      int channel1 = extractChannel(buffer, 0); // For example
      int channel2 = extractChannel(buffer, 1);

      // Map to PWM (0–255)
      int pwm1 = map(channel1, 1000, 2000, 0, 255);
      int pwm2 = map(channel2, 1000, 2000, 0, 255);

      analogWrite(channel1OutputPin, pwm1);
      analogWrite(channel2OutputPin, pwm2);

      Serial.print("Ch1 PWM: "); Serial.print(pwm1);
      Serial.print(" | Ch2 PWM: "); Serial.println(pwm2);

      bufferIndex = 0; // Reset buffer
    }
  }
}

// Dummy parser example
int extractChannel(uint8_t *packet, int channelIndex) {
  // Proper CRSF parsing needed here
  // This is a placeholder: normally channels are packed
  return 1500; // Centered 1500us by default
}

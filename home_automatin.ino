 Include necessary libraries
#include SoftwareSerial.h

 Define relay pin
const int relayPin = 7;

 Define software serial pins for Bluetooth module
SoftwareSerial bluetooth(2, 3);  RX, TX

void setup() {
   Set relay pin as an output
  pinMode(relayPin, OUTPUT);
  
   Start serial communication with a baud rate of 9600 for debugging
  Serial.begin(9600);
  
   Start Bluetooth communication with a baud rate of 9600
  bluetooth.begin(9600);
}

void loop() {
   Check if data is available from Bluetooth module
  if (bluetooth.available()  0) {
    char command = bluetooth.read();  Read the incoming command
    
     Process the received command
    if (command == '1') {
      digitalWrite(relayPin, HIGH);  Turn on the device (e.g., light)
      Serial.println(Device turned ON);
    } else if (command == '0') {
      digitalWrite(relayPin, LOW);  Turn off the device
      Serial.println(Device turned OFF);
    }
  }
}

#include <L298N.h>
#include <SoftwareSerial.h>

// Create object named bt of the class SoftwareSerial 
SoftwareSerial bt(12, 13); // (Rx, Tx) 
// Without Enable pin with jumper in place
L298N motor1(5, 6);
L298N motor2(9, 11);

void setup() {
  bt.begin(9600); // Define baud rate for software serial communication
  Serial.begin(9600); // Define baud rate for serial communication
}

void loop() {
  if (bt.available()) { // If data is available on serial port
    char c = bt.read(); // Read a character from the serial port
    Serial.println(c); // Print the character received on the serial monitor

    // Control logic for motors based on received character
    if (c == 'F') { // Move forward
      Serial.println("Forward");
      motor1.forward();
      motor2.forward();
    } 
    else if (c == 'B') { // Move backward
      Serial.println("Backward");
      motor1.backward();
      motor2.backward();
    } 
    else if (c == 'L') { // Turn left
      Serial.println("Left");
      motor2.backward();
      motor1.forward();
    } 
    else if (c == 'R') { // Turn right
      Serial.println("Right");
      motor2.forward();
      motor1.backward();
    } 
    else { // Stop the motors if any other character is received
      Serial.println("Stop");
      motor1.stop();
      motor2.stop();
    }
  }
}

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// Relay pin connections
int light = 26;
int fan   = 25;
int tv    = 33;
int ac    = 32;

void setup() {

  // Set all relay pins as OUTPUT
  pinMode(light, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(tv, OUTPUT);
  pinMode(ac, OUTPUT);

  // Turn OFF all devices at start
  digitalWrite(light, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(tv, LOW);
  digitalWrite(ac, LOW);

  // Start Bluetooth and Serial
  Serial.begin(9600);
  SerialBT.begin("ESP32_Voice_Control");

  Serial.println("Bluetooth is ready");
}

void loop() {

  // Check if any voice command is received
  if (SerialBT.available()) {

    // Read command from Bluetooth
    String command = SerialBT.readString();
    command.toLowerCase();   // convert to lowercase
    Serial.println(command);

    // ----- LIGHT -----
    if (command.indexOf("light on") >= 0)
      digitalWrite(light, HIGH);
    else if (command.indexOf("light off") >= 0)
      digitalWrite(light, LOW);

    // ----- FAN -----
    else if (command.indexOf("fan on") >= 0)
      digitalWrite(fan, HIGH);
    else if (command.indexOf("fan off") >= 0)
      digitalWrite(fan, LOW);

    // ----- TV -----
    else if (command.indexOf("tv on") >= 0)
      digitalWrite(tv, HIGH);
    else if (command.indexOf("tv off") >= 0)
      digitalWrite(tv, LOW);

    // ----- AC -----
    else if (command.indexOf("ac on") >= 0)
      digitalWrite(ac, HIGH);
    else if (command.indexOf("ac off") >= 0)
      digitalWrite(ac, LOW);
  }
}

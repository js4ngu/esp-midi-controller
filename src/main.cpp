#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    Serial.println("ESP32 Ready!");
}

void loop() {
    Serial.println("Hello, ESP32!");
    delay(1000);
}

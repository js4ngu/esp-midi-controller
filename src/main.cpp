#include <WiFi.h>
#include "webpage.h"

const char* ssid = "ESP32-AP";
const char* ap_password = "12345678";
const int ledPin = 2; // LED 핀 번호

WebServer server(80);

void setup() {
    Serial.begin(115200);

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);

    if (!initializeSPIFFS()) {
        Serial.println("SPIFFS Initialization Failed");
        while (true);
    }

    WiFi.softAP(ssid, ap_password);
    Serial.println("Access Point started");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());

    setupWebServer(server, ledPin); // 핀 번호 전달
}

void loop() {
    server.handleClient();
}

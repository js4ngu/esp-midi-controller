#include "webpage.h"
#include <SPIFFS.h>

bool initializeSPIFFS() {
    if (!SPIFFS.begin(true)) {
        Serial.println("SPIFFS Mount Failed");
        return false;
    }
    Serial.println("SPIFFS Initialized");
    return true;
}

void setupWebServer(WebServer &server, int ledPin) {
    server.on("/", HTTP_GET, [&server]() {
        File file = SPIFFS.open("/index.html", "r");
        if (!file) {
            server.send(404, "text/plain", "File not found");
            return;
        }
        String content = file.readString();
        server.send(200, "text/html", content);
        file.close();
    });

    server.on("/led/on", HTTP_GET, [&server, ledPin]() {
        digitalWrite(ledPin, HIGH);
        server.send(200, "text/plain", "LED is ON");
    });

    server.on("/led/off", HTTP_GET, [&server, ledPin]() {
        digitalWrite(ledPin, LOW);
        server.send(200, "text/plain", "LED is OFF");
    });

    server.begin();
    Serial.println("Server started");
}

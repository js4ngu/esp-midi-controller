#include <WiFi.h>
#include <WebServer.h>

// AP 설정
const char* ssid = "ESP32-AP";      // ESP32의 Wi-Fi 이름
const char* password = "12345678";  // 접속 비밀번호 (8자 이상)

// LED 핀 설정
const int ledPin = 2; // 내장 LED 핀 (GPIO2)

// 웹 서버 생성
WebServer server(80);

// HTML 페이지
String htmlContent = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
    <title>ESP32 Control</title>
</head>
<body>
    <h1>ESP32 LED Control</h1>
    <button onclick="fetch('/led/on')">Turn LED ON</button>
    <button onclick="fetch('/led/off')">Turn LED OFF</button>
</body>
</html>
)rawliteral";

// LED ON 핸들러
void handleLedOn() {
    digitalWrite(ledPin, HIGH); // LED 켜기
    server.send(200, "text/plain", "LED is ON");
}

// LED OFF 핸들러
void handleLedOff() {
    digitalWrite(ledPin, LOW); // LED 끄기
    server.send(200, "text/plain", "LED is OFF");
}

// HTML 페이지 핸들러
void handleRoot() {
    server.send(200, "text/html", htmlContent);
}

void setup() {
    // 시리얼 초기화
    Serial.begin(115200);

    // LED 핀 설정
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW); // 초기 상태: OFF

    // Wi-Fi Access Point 시작
    WiFi.softAP(ssid, password);
    Serial.println("Access Point started.");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());

    // 라우트 설정
    server.on("/", handleRoot);      // 기본 페이지
    server.on("/led/on", handleLedOn);  // LED ON
    server.on("/led/off", handleLedOff); // LED OFF

    // 서버 시작
    server.begin();
    Serial.println("Web server started.");
}

void loop() {
    // 클라이언트 요청 처리
    server.handleClient();
}

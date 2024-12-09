#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <WebServer.h>

// SPIFFS 초기화 함수
bool initializeSPIFFS();

// 웹 서버 초기화 함수
void setupWebServer(WebServer &server, int ledPin);

#endif

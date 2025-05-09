#ifndef WIFI_CONNECT_H
#define WIFI_CONNECT_H

#include <WiFi.h>

#define WIFI_TIMEOUT_MS 10000
#define WIFI_LED LED_BUILTIN

#define YOUR_WIFI_SSID ""
#define YOUR_WIFI_PASSWORD ""

void blinkLED(int times, int delayMs = 250) {
  for (int i = 0; i < times; i++) {
    digitalWrite(WIFI_LED, HIGH);
    delay(delayMs);
    digitalWrite(WIFI_LED, LOW);
    delay(delayMs);
  }
}

void connectToWiFi() {
  WiFi.begin(YOUR_WIFI_SSID, YOUR_WIFI_PASSWORD);

  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    blinkLED(1);  // Success
  } else {
    blinkLED(3);  // Failure
  }
}
#endif

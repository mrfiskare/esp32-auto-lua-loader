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

  Serial.print("Connecting to WiFi");

  unsigned long startAttemptTime = millis();

  while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS) {
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    blinkLED(1);  // Success
  } else {
    Serial.println("\nWiFi connection failed!");
    blinkLED(3);  // Failure
  }
}

#include "wifi_connect.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  connectToWiFi();
}

void loop() {
  // Empty for now
}

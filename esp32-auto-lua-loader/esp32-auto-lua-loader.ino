#include <ESPmDNS.h>
#include "wifi_connect.h"

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  connectToWiFi();
  initLogger();
  MDNS.begin("esp32");
}

void loop() {
}

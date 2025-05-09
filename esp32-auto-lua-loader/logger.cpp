#include "logger.h"

AsyncEventSource events("/events");
AsyncWebServer server(80);

void initLogger() {
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", R"rawliteral(
      <!DOCTYPE html><html><body>
      <pre id="log"></pre>
      <script>
        const log = document.getElementById('log');
        const evtSource = new EventSource('/events');
        evtSource.onmessage = function(e) {
          log.textContent += e.data + "\n";
          log.scrollTop = log.scrollHeight;
        };
      </script>
      </body></html>
    )rawliteral");
  });

  events.onConnect([](AsyncEventSourceClient *client){
    logMessage("Client connected to log stream");
  });

  server.addHandler(&events);
  server.begin();
}

void logMessage(const String& message) {
  Serial.println(message);
  events.send(message.c_str(), "message", millis());
}


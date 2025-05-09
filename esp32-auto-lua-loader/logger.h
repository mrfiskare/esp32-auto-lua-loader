#ifndef LOGGER_H
#define LOGGER_H

#include <Arduino.h>
#include <ESPAsyncWebServer.h>

extern AsyncEventSource events;  // Defined in logger.cpp

void initLogger();
void logMessage(const String& message);

#endif


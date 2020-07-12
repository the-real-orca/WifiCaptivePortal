#include <Arduino.h>

// JSON
#include <ArduinoJson.h>

// Captive Portal
#include "CaptivePortal.h"
CaptivePortal captivePortal;

void handleCustom()
{
	captivePortal.sendFinal(200, "text/plain", "OK");
}

void setup()
{
	Serial.begin(115200);
	while (!Serial)
	{
		// wait for serial port to connect. Needed for native USB
	}
	Serial.println("\nWifi Config & Captive Portal Test");

	captivePortal.setup();

	// custom pages
	captivePortal.on("/custom", handleCustom);

	captivePortal.begin();

	Serial.println("Captive Portal started!");
}

void loop()
{
	captivePortal.loop();
}

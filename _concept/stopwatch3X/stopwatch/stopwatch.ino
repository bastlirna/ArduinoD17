#include <Arduino.h>

#include "hal.h"
#include "core.h"

void setup() {
	Serial.begin(9600);
	Serial.println("SETUP");

	update_display(1);

	core_setup();
}

void loop() {
	btn_loop();
	core_loop();
}

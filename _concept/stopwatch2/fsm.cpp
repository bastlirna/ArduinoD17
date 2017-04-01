#include "fsm.h"

#include <Arduino.h>

Machine::Machine()
{
}

void Machine::loop() {
	if (current_state) {
		current_state();
	}
}

void Machine::change(void_fn_t state) {
	current_state = state;
	previous_millis = millis();
}

unsigned long Machine::millis() {
	return millis() - previous_millis;
}


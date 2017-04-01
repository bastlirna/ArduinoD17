#include "hal.h"
#include "fsm.h"

Machine m = Machine();

void a() {
	if (m.millis() > 1000) {
		Serial.println("a");
		m.change(a);
	}
}


void b() {
	if (m.millis() > 1000) {
		m.change(a);
	}

}



void setup() {
	Serial.begin(9600);
	Serial.println("SETUP");

	//m.change(a);
}

int counter = 0;


void loop() {

	btn_loop();

	if (btn_event == BTN_SHORT_PRESS) {
		Serial.println("SHORT");
		btn_event = BTN_IDLE;

		m.change(b);
	}


	if (btn_event == BTN_LONG_PRESS) {
		Serial.println("LONG");
		btn_event = BTN_IDLE;

		m.change(a);
	}

	m.loop();

	//delay(100);

}
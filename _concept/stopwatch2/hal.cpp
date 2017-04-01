#include <Wire.h>
#include <edushield.h>
#include <Bounce2.h>
#include "hal.h"
#include <Arduino.h>

// --- funkce pro display -----------------------------------------------------

static int last_num;

void display(int num) {
  if (num != last_num) {
  		Display.number(num);
  		last_num = num;
	}
}

// --- funkce tlaátka ---------------------------------------------------------

typedef void (*fn)(void);

unsigned long btn_press_time;

Bounce btn = Bounce(BTN_PIN, 10);

// stavy tlačítka

void btn_idle_state();
void btn_press_state();
void btn_wait_for_ack_state();

int btn_event = BTN_IDLE;
fn btn_internal_state = btn_idle_state;

void btn_idle_state() {
	bool changed = btn.update();

	if (changed && btn.read() == false) {
				btn_press_time = millis();
		btn_internal_state = btn_press_state;
	}
}

void btn_press_state() {
	
	bool changed = btn.update();

	if (millis() - btn_press_time > 1000) {
		// tlačítko je už stisklé díle než 1s
				btn_event = BTN_LONG_PRESS;

				btn_internal_state = btn_wait_for_ack_state;
		return;
	}

	if (changed && btn.read() == true) {
				btn_event = BTN_SHORT_PRESS;
				btn_internal_state = btn_wait_for_ack_state;
	}
}

void btn_wait_for_ack_state() {
	
		btn.update();
	if (btn_event == BTN_IDLE) {
		// událost byla zpracována a tlačítko puštěno
				btn_internal_state = btn_idle_state;
	}
}


// loop funkce tlačítka

void btn_loop() {
	btn_internal_state();
}

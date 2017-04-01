#include "hal.h"

#include <Wire.h>
#include <edushield.h>
#include <Bounce2.h>
#include <Arduino.h>

// --- funkce pro display -----------------------------------------------------

// 7-segment font
const byte NUMBER_FONT[] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111, // 9
  0b01110111, // A
  0b01111100, // B
  0b00111001, // C
  0b01011110, // D
  0b01111001, // E
  0b01110001  // F
};

static int last_num;

byte current_digit[4];

void digit(byte n, byte v) {

	if (current_digit[n] == v) {
		return;
	}

	Wire.beginTransmission(0x27);
	Wire.write(n);
	Wire.write(v);
	Wire.endTransmission();

	current_digit[n] = v;
}

void display2(int num) {
  if (num != last_num) {
  		Display.number(num);
  		last_num = num;
	}
}

void update_display(unsigned int time) {
	unsigned long t = min(time, 99990);

	byte a = t / 10000;
	t = t % 10000;

	byte b = t / 1000;
	t = t % 1000;

	byte c = t / 100;
	t = t % 100;

	byte d = t / 10;

	digit(0, NUMBER_FONT[a]);
	digit(1, NUMBER_FONT[b] | 0b10000000);
	digit(2, NUMBER_FONT[c]);
	digit(3, NUMBER_FONT[d]);
}

void display_off() {
  digit(0, 0);
  digit(1, 0);
  digit(2, 0);
  digit(3, 0);
}

// --- funkce tlaátka ---------------------------------------------------------

typedef void (*fn)(void);

unsigned long btn_press_time = 0;

Bounce btn = Bounce(BTN_PIN, 5);

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

#include <Arduino.h>
#include <Wire.h>
#include <edushield.h>
#include <Bounce2.h>

#define BUTTON_PIN 2

Bounce btn = Bounce(BUTTON_PIN, 10);

int counter = 0;
bool btn_is_pressed = false;
unsigned long btn_press_time;

typedef enum { BTN_IDLE, BTN_SHORT_PRESS, BTN_LONG_PRESS } btn_event_t;

btn_event_t btn_event = BTN_IDLE;

void button_loop() {

  bool changed = btn.update();

  if (btn_event != BTN_IDLE) return;

  if (changed) {
    if (btn.read() == 0) { //
      btn_is_pressed = true;
      btn_press_time = millis();
    } else {
      if (btn_is_pressed)
        btn_event = BTN_SHORT_PRESS;
      btn_is_pressed = false;
    }
  }

  if (btn_is_pressed && millis() - btn_press_time > 1000) {
    btn_event = BTN_LONG_PRESS;
    btn_is_pressed = false;
  }
}



void display(int num) {
  static int last_num;
  if (num == last_num) return;

  Display.number(num);
  last_num = num;
}

typedef void (*fn)(void);

fn current_state;
unsigned long state_start_time;

void change_state(fn state) {
  current_state = state;
  state_start_time = millis();
}

unsigned long state_millis() {
  return millis() - state_start_time;
}

unsigned long sw_start_time;

void state_lap();
void state_running();

void state_running() {

  if (btn_event == BTN_SHORT_PRESS) {
    change_state(state_lap);
    last_lap_time = millis();
    btn_event = BTN_IDLE;
  }

  if (btn_event == BTN_LONG_PRESS) {
    // TODO
    btn_event = BTN_IDLE;
  }

  unsigned long now = millis() - sw_start_time;
  display(now / 10);
}

void state_lap() {

  if (state_millis() > 1000) {
    change_state(state_running);
  }

  display(int num)
}

void state_stop() {
  if (btn_event == BTN_SHORT_PRESS) { // start stopwatch
    sw_start_time = millis();
    change_state(state_running);
    btn_event = BTN_IDLE;
  }
}





void setup() {
  Serial.begin(9600);
  Display.number(0);

  current_state = state_stop;
}


void loop () {

  button_loop();

  current_state();

}

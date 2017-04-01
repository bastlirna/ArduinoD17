#include "core.h"
#include "hal.h"
#include "time.h"
#include <Arduino.h>

typedef void (*fn)(void);

fn current_state;

unsigned long state_start_time, last_lap_time;

// ---

void change_state(fn state) {
  current_state = state;
  state_start_time = millis();
}

unsigned long state_millis() {
  return millis() - state_start_time;
}

// ---

unsigned long sw_start_time;

void state_stop();
void state_lap();
void state_running();
void state_finish();

// ---

void state_stop() {
  if (btn_event == BTN_SHORT_PRESS) { // start stopwatch
    sw_start();
    change_state(state_running);
    btn_event = BTN_IDLE;
  }

  if (btn_event == BTN_LONG_PRESS) {
    btn_event = BTN_IDLE;
  }

  display_zero();
}

void state_running() {

  if (btn_event == BTN_SHORT_PRESS) {
    sw_lap();
    change_state(state_lap);
    btn_event = BTN_IDLE;
  }

  if (btn_event == BTN_LONG_PRESS) {
    sw_stop(millis() - btn_press_time);
    change_state(state_finish);
    btn_event = BTN_IDLE;
  }

  unsigned long now = sw_get_time();
  update_display(now);
}

void state_lap() {
  if (state_millis() > 600) {
    change_state(state_running);
    return;
  }

  if (btn_event == BTN_SHORT_PRESS) {
    sw_lap();
    update_display(sw_last_lap_time());
    change_state(state_lap);
    btn_event = BTN_IDLE;
  }

  if (btn_event == BTN_LONG_PRESS) {
    sw_stop(millis() - btn_press_time);
    change_state(state_finish);
    btn_event = BTN_IDLE;
  }
}

void state_finish() {
  if (btn_event != BTN_IDLE) {
    change_state(state_stop);
    update_display(0);
    btn_event = BTN_IDLE;
  }

  if (state_millis() > 600) {
    update_display(sw_get_time());
  } else if (state_millis() > 400) {
    display_off();
  } else if (state_millis() > 200) {
    update_display(sw_get_time());
  } else {
    display_off();
  }
}

// ---

void core_setup() {
  change_state(state_stop);
}

void core_loop() {
  current_state();
}

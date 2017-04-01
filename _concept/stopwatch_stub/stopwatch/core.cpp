#include "core.h"
#include "hal.h"
#include "time.h"
#include <Arduino.h>

typedef void (*fn)(void);

fn current_state;

// ---

void change_state(fn state) {
  current_state = state;
  state_start_time = millis();
}

unsigned long state_millis() {
  return millis() - state_start_time;
}

// ---

void state_a();
void state_b();

// ---

void state_a() {
}

void state_b() {
}

// ---

void core_setup() {
  change_state(state_a);
}

void core_loop() {
  current_state();
}

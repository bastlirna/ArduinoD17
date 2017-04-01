#include "time.h"
#include <Arduino.h>

static unsigned long sw_start_time;
static unsigned long sw_stop_time;
static unsigned long sw_last_lap;

bool is_running = false;

void sw_stop() {
  sw_stop(0);
}

void sw_stop(int offset = 0) {
  sw_stop_time = millis() - offset;
  is_running = false;
}

void sw_start() {
  sw_start_time = millis();
  is_running = true;
}

void sw_lap() {
  sw_last_lap = millis();
}

unsigned long sw_get_time() {
  if (is_running) {
    return millis() - sw_start_time;
  } else {
    return sw_stop_time - sw_start_time;
  }
}

unsigned long sw_last_lap_time() {
  return sw_last_lap - sw_start_time;
}

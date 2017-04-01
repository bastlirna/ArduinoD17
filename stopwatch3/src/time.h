#ifndef _TIME_H_
#define _TIME_H_

void sw_stop();
void sw_stop(int offset);
void sw_start();
void sw_lap();

unsigned long sw_get_time();
unsigned long sw_last_lap_time();

#endif

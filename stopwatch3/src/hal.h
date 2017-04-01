#ifndef _HAL_H_
#define _HAL_H_

// --- funkce pro display -----------------------------------------------------

/**
 *	Zobrazí na displeji dané číslo
 */
void display2(int num);

void update_display(unsigned int time);
void display_off();

// --- funkce pro tlačítko ----------------------------------------------------

#define BTN_PIN 2

// seznam událostí, které tlačítko může vyvolat
typedef enum {
	BTN_IDLE = 0, // tlačítko je v klidu
	BTN_SHORT_PRESS = 1, // krátký stisk tlačítka
	BTN_LONG_PRESS = 2 // dlouhá stisk tlačítka
} btn_event_t;

// událost tlačítka
extern int btn_event;

extern unsigned long btn_press_time;

// vunkce pro kontrolu tlačítka, musí se volat periodicky v hlavní loop
void btn_loop();

#endif

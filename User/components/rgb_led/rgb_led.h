/*
 * rgb_led.h
 *
 *  Created on: May 5, 2021
 *      Author: KhanhDinh
 */

#ifndef COMPONENTS_RGB_LED_RGB_LED_H_
#define COMPONENTS_RGB_LED_RGB_LED_H_
#include "board.h"
#include "stdbool.h"
#include "stdint.h"

typedef enum LED_COLOR{
	RED = 0,
	BLUE,
	YELLOW,
	BLINK,
	NONE
} LED_COLOR;

typedef struct RGB_LED_t RGB_LED;
struct RGB_LED_t{
	LED_COLOR	color;
	bool		toggle_flag;
	bool		blink_state;
	uint16_t	blink_time_ms;
	uint16_t	blink_interval_ms;
	void		(*set_color)(RGB_LED*);
};

void led_set_color(RGB_LED* p_led, LED_COLOR);
void blink_led(RGB_LED* p_led, uint32_t timestamp);

#endif /* COMPONENTS_RGB_LED_RGB_LED_H_ */

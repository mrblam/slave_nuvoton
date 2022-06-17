/*
 * rgb_led.c
 *
 *  Created on: May 5, 2021
 *      Author: KhanhDinh
 */

#include "rgb_led.h"


void led_set_color(RGB_LED* p_led, LED_COLOR color){
	//p_led->color = color;
	switch(color){
	case NONE:
		SET_LED_R_STATE	= LOW;
		SET_LED_G_STATE	= LOW;
		SET_LED_B_STATE	= LOW;
		break;
	case RED:
		SET_LED_R_STATE	= HIGH;
		SET_LED_G_STATE	= LOW;
		SET_LED_B_STATE	= LOW;
		break;
	case BLUE:
		LED_R_LOW;
		LED_G_HIGH;
		break;
	case YELLOW:
        LED_G_HIGH;
		LED_R_HIGH;
		break;
	default:
		break;
	}
}



void blink_led(RGB_LED* p_led, uint32_t timestamp){
	if(p_led->blink_state == 0) return;
	else{
		if(p_led->blink_time_ms == 0){
			led_set_color(p_led, p_led->color);
			p_led->blink_state--;
			return;
		}
		if(p_led->toggle_flag){
			led_set_color(p_led, NONE);
			p_led->toggle_flag--;
		}
		else{
			led_set_color(p_led, p_led->color);
			p_led->toggle_flag++;
		}
		p_led->blink_time_ms-=100;
	}
}



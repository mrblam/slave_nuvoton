/*
 * switch.c
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#include "switch.h"

Switch* sw_construct(void){
	Switch* p_sw = (Switch*)malloc(sizeof(Switch));
	while(p_sw == NULL);
	return p_sw;
}

void sw_process(Switch* p_sw, unsigned char state){
	if(state == SW_ST_ON){
		sw_on(p_sw);
		return;
	}
	sw_off(p_sw);
}

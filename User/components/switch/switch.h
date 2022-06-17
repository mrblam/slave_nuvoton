/*
 * switch.h
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#ifndef COMPONENTS_SWITCH_SWITCH_H_
#define COMPONENTS_SWITCH_SWITCH_H_

#include "stdlib.h"

typedef enum SW_STATE{
	SW_ST_OFF = 0,
	SW_ST_ON,
	SW_ST_FAIL
}SW_STATE;

typedef struct Switch_t Switch;
typedef void (*sw_act)(Switch* p_sw);

struct Switch_t{
	SW_STATE	state;
	sw_act 		sw_on;
	sw_act		sw_off;
	unsigned char		(*get_sw_state)(Switch* p_sw);
};

Switch* sw_construct(void);
void sw_process(Switch* p_sw, unsigned char state);

static inline void sw_on(Switch* p_sw){
	p_sw->sw_on(p_sw);
}

static inline void sw_off(Switch* p_sw){
	p_sw->sw_off(p_sw);
}

static inline SW_STATE sw_get_state(Switch* p_sw){
	return p_sw->state;
}

static inline void sw_update_state(Switch* p_sw){
	p_sw->state = sw_get_state(p_sw);
}

#endif /* COMPONENTS_SWITCH_SWITCH_H_ */

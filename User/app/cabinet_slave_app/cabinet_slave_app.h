/*
 * cabinet_slave_app.h
 *
 *  Created on: Jun 1, 2022
 *      Author: hoanpx
 */

#ifndef USER_APP_CABINET_SLAVE_APP_CABINET_SLAVE_APP_H_
#define USER_APP_CABINET_SLAVE_APP_CABINET_SLAVE_APP_H_

#include "switch.h"
#include "ntc.h"
#include "rs485_slave.h"
#include "rgb_led.h"

typedef enum CABINET_SLAVE_STATE{
	CABINET_INACTIVE,
	CABINET_EMPTY,
	CABINET_STANDBY,
	CABINET_MAINTAIN,
	CABINET_FAIL
}CABINET_SLAVE_STATE;

typedef struct	Cabinet_slave_app_t Cabinet_slave_app;
struct Cabinet_slave_app_t{
	RS485_Slave			base;
	CABINET_SLAVE_STATE state;
	Switch				door;
	Switch				fan;
	Switch				sw_charge;
	Switch	 			node_id_pin;
	Switch 				standby_led;
	NTC*				temp_ss;
	RGB_LED				cabinet_led;
	uint32_t 			timeout;
};

void cab_slave_app_update_temp(Cabinet_slave_app* p_app, uint32_t timestamp);




#endif /* USER_APP_CABINET_SLAVE_APP_CABINET_SLAVE_APP_H_ */

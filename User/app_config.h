/*
 * app_config.h
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#ifndef APP_CONFIG_H_
#define APP_CONFIG_H_

#define USE_STD_LIBRARY				0

/* 1: RS485 Tx
 * 2: RS485 Rx
 * 3: Switch (Door, Fan, Charger, LED, Node ID)
 */

#define ADC_RESOLUTION			1023
#define VREF0					5000   // Nuvoton had define VREF

#define BLINK_INTERVAL_mS		500UL
#define BLINK_TIME_mS			5000
#define DOOR_STABLE_COUNTER		500UL

#define USE_EXTERNAL_CRYSTAL	        1

#define SYSTICK_FREQ_Hz			10


#endif /* APP_CONFIG_H_ */

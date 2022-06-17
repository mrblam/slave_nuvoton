/*
 * cabinet_slave_hw.h
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#ifndef BOARD_CABINET_SLAVE_HW_CABINET_SLAVE_HW_H_
#define BOARD_CABINET_SLAVE_HW_CABINET_SLAVE_HW_H_

#include "stdint.h"
#include "NuMicro.h"
extern uint8_t slave_address;
/* State PIN*/
#define HIGH			1
#define LOW				0

/* Cabinet Door */
#define DOOR_SW_PORT			PC
#define DOOR_SW_PIN				BIT4
#define SET_DOOR_STATE			PC4

#define DOOR_SW_ON				SET_DOOR_STATE = HIGH
#define DOOR_SW_OFF				SET_DOOR_STATE = LOW

#define DOOR_ST_PORT			PD
#define DOOR_ST_PIN   			BIT6 ///////cong tac hanh trinh
#define GET_DOOR_STATE			PD6

/* Cabinet fan */
#define FAN_SW_PORT				PA
#define FAN_SW_PIN				BIT2
#define SET_FAN_STATE			PA2

#define FAN_SW_ON				SET_FAN_STATE = HIGH
#define FAN_SW_OFF				SET_FAN_STATE = LOW

/* Node ID Pin */
#define NODE_ID_PORT			PC
#define NODE_ID_PIN				BIT0
#define SET_NODE_STATE			PC0

#define NODE_ID_HIGH			SET_NODE_STATE = HIGH
#define NODE_ID_LOW				SET_NODE_STATE = LOW

/* Cabinet Charger switch */
#define CHARGER_SW_PORT			PD
#define CHARGER_SW_PIN			BIT1
#define SET_CHARGER_STATE		PD1

#define CHARGER_SW_ON
#define CHARGER_SW_OFF

/* RS-485 ID */
#define ID0123_PORT
#define ID4_PORT
#define ID0_PIN
#define ID1_PIN
#define ID2_PIN
#define ID3_PIN
#define ID4_PIN
#define	GET_ID_ADDR0
#define	GET_ID_ADDR1
#define	GET_ID_ADDR2
#define	GET_ID_ADDR3
#define	GET_ID_ADDR4

/* RGB LED */
/* Disable Blue LED, set high to turn-on Mosfet on LED module */
#define LED_R_PORT			PD
#define LED_R_PIN			BIT7
#define SET_LED_R_STATE		PD7

#define LED_G_PORT			PC
#define LED_G_PIN			BIT2
#define SET_LED_G_STATE		PC2

#define LED_B_PORT			PC
#define LED_B_PIN			BIT1
#define SET_LED_B_STATE		PC1

#define LED_R_HIGH			//GPIO_WriteHigh(LED_RGB_PORT, LED_R_PIN)
#define LED_G_HIGH			//GPIO_WriteHigh(LED_RGB_PORT, LED_G_PIN)
#define LED_B_HIGH			//GPIO_WriteHigh(LED_RGB_PORT, LED_B_PIN)

#define LED_R_LOW			//GPIO_WriteLow(LED_RGB_PORT, LED_R_PIN)
#define LED_G_LOW			//GPIO_WriteLow(LED_RGB_PORT, LED_G_PIN)
#define LED_B_LOW			//GPIO_WriteLow(LED_RGB_PORT, LED_B_PIN)

/* RS_485 Pin */
#define EN_RS485_PORT		PC
#define EN_RS485_PIN		BIT7
#define SET_RS485_STATE		PC7

#define EN_RS485_HIGH		SET_RS485_STATE = HIGH
#define EN_RS485_LOW		SET_RS485_STATE = LOW

extern uint8_t door_state;
extern uint8_t door_state1;

void cabinet_slave_hw_init(void);
void door_update_state(void);

#endif /* BOARD_CABINET_SLAVE_HW_CABINET_SLAVE_HW_H_ */

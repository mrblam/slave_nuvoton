/*
 * cabinet_slave_hw.c
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#include "cabinet_slave_hw.h"

uint8_t door_state;
uint8_t slave_address;
uint8_t door_state1;

static void door_init(void);
static void fan_sw_init(void);
static void charger_sw_init(void);
static void node_id_sw_init(void);
static void rgb_led_init(void);
static void rs485_io_hw_init(void);

void cabinet_slave_hw_init(void){
	rs485_io_hw_init();
	rgb_led_init();
	fan_sw_init();
	door_init();
	charger_sw_init();
	node_id_sw_init();
}

static void door_init(void){

	//GPIO_SetMode(DOOR_SW_PORT, DOOR_SW_PIN, GPIO_MODE_OUTPUT);
	//DOOR_SW_ON;
	GPIO_SetMode(DOOR_ST_PORT, DOOR_ST_PIN, GPIO_MODE_INPUT);
	//GPIO_SetPullCtl(DOOR_ST_PORT, DOOR_ST_PIN,GPIO_PUSEL_PULL_UP);
}

static void fan_sw_init(void){
	GPIO_SetMode(FAN_SW_PORT, FAN_SW_PIN, GPIO_MODE_OUTPUT);
}

static void charger_sw_init(void){
	GPIO_SetMode(CHARGER_SW_PORT, CHARGER_SW_PIN, GPIO_MODE_OUTPUT);
}

static void node_id_sw_init(void){
	GPIO_SetMode(NODE_ID_PORT, NODE_ID_PIN, GPIO_MODE_OUTPUT);

}

static void rs485_io_hw_init(void){
	GPIO_SetMode(EN_RS485_PORT, EN_RS485_PIN, GPIO_MODE_OUTPUT);

}

static void rgb_led_init(void){

	GPIO_SetMode(LED_R_PORT, LED_R_PIN, GPIO_MODE_OUTPUT);
	GPIO_SetMode(LED_G_PORT, LED_G_PIN, GPIO_MODE_OUTPUT);
	GPIO_SetMode(LED_B_PORT, LED_B_PIN, GPIO_MODE_OUTPUT);
}



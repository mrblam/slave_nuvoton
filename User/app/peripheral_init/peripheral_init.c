/*
 * peripheral_init.c
 *
 *  Created on: Jun 1, 2022
 *      Author: hoanpx
 */



#include "peripheral_init.h"
#include "rs485_slave.h"
static const uint16_t ntc_lookups[] = {
	    33889,//0
	    32146,//1
	    30504,//2
	    28957,//3
	    27499,//4
	    26124,//5
	    24827,//6
	    23603,//7
	    22447,//8
	    21356,//9
	    20324,//10
	    19350,//11
	    18428,//12
	    17556,//13
	    16731,//14
	    15951,//15
	    15211,//16
	    14511,//17
	    13847,//18
	    13219,//19
	    12622,//20
	    12056,//21
	    11520,//22
	    11010,//23
	    10526,//24
	    10067,//25
	    9630,//26
	    9215,//27
	    8821,//28
	    8446,//29
	    8089,//30
	    7750,//31
	    7426,//32
	    7119,//33
	    6826,//34
	    6546,//35
	    6280,//36
	    6026,//37
	    5785,//38
	    5554,//39
	    5334,//40
	    5124,//41
	    4923,//42
	    4731,//43
	    4548,//44
	    4374,//45
	    4207,//46
	    4047,//47
	    3894,//48
	    3748,//49
	    3609,//50
	    3475,//51
	    3347,//52
	    3225,//53
	    3107,//54
	    2995,//55
	    2887,//56
	    2784,//57
	    2685,//58
	    2590,//59
	    2499,//60
	    2412,//61
	    2329,//62
	    2248,//63
	    2171,//64
	    2097,//65
	    2026,//66
	    1958,//67
	    1892,//68
	    1829,//69
	    1769,//70
	    1710,//71
	    1654,//72
	    1601,//73
	    1549,//74
	    1499,//75
	    1451,//76
	    1405,//77
	    1360,//78
	    1318,//79
	    1276,//80
	    1237,//81
	    1198,//82
	    1162,//83
	    1126,//84
	    1092,//85
	    1059,//86
	    1027,//87
	    996,//88
	    966,//89
	    938,//90
	    910,//91
	    884,//92
	    858,//93
	    833,//94
	    809,//95
	    786,//96
	    763,//97
	    742,//98
	    721,//99
	    700,//100
};

static void door_sw_on(Switch* p_sw);
static uint8_t	door_get_state(Switch* p_sw);
static void node_id_sw_on(Switch* p_sw);
static void node_id_sw_off(Switch* p_sw);
static void fan_sw_on(Switch* p_sw);
static void fan_sw_off(Switch* p_sw);
static void charger_sw_on(Switch* p_sw);
static void charger_sw_off(Switch* p_sw);
static void standby_led_sw_on(Switch* p_sw);
static void standby_led_sw_off(Switch* p_sw);
static void rs485_slave_sync_data_serialize_impl(RS485_Slave* p_485s);

void peripheral_init(Cabinet_slave_app* p_app){
	p_app->temp_ss = ntc_construct();
	ntc_set_lut(p_app->temp_ss, ntc_lookups);

	p_app->door.sw_on = door_sw_on;
	p_app->door.get_sw_state = door_get_state;
	p_app->node_id_pin.sw_on = node_id_sw_on;
	p_app->node_id_pin.sw_off = node_id_sw_off;
	p_app->fan.sw_on = fan_sw_on;
	p_app->fan.sw_off = fan_sw_off;
	p_app->sw_charge.sw_on = charger_sw_on;
	p_app->sw_charge.sw_off = charger_sw_off;
	p_app->standby_led.sw_on = standby_led_sw_on;
	p_app->standby_led.sw_off = standby_led_sw_off;

	p_app->base.sync_data_serialize = rs485_slave_sync_data_serialize_impl;
}

static void door_sw_on(Switch* p_sw){

	GPIO_SetMode(DOOR_SW_PORT, DOOR_SW_PIN, GPIO_MODE_OUTPUT);

	(void)p_sw;
	for(uint8_t i = 0; i < 3; i++){

//		SET_DOOR_STATE = LOW;
//		for(uint32_t cnt = 0; cnt < 100000;  cnt++);
#if 1

		SET_DOOR_STATE = LOW;
		for(uint32_t cnt = 0; cnt < 200000;  cnt++);
		SET_DOOR_STATE = HIGH;
		for(uint32_t cnt = 0; cnt < 100000;  cnt++);

		//if(GET_DOOR_STATE == 1) return;
#endif
	}
	if(door_state != GET_DOOR_STATE){
		selex_bss_app.cabinet_led.blink_state++;
		selex_bss_app.cabinet_led.blink_time_ms = 5000;
	}
	door_state = GET_DOOR_STATE;
}

static uint8_t door_get_state(Switch* p_sw){
	(void)p_sw;
	return !GET_DOOR_STATE;
}

static void node_id_sw_on(Switch* p_sw){
	(void)p_sw;
	NODE_ID_HIGH;
	p_sw->state = SW_ST_ON;
}

static void node_id_sw_off(Switch* p_sw){
	(void)p_sw;
	NODE_ID_LOW;
	p_sw->state = SW_ST_OFF;
}

static void fan_sw_on(Switch* p_sw){
	(void)p_sw;
	FAN_SW_ON;
	p_sw->state = SW_ST_ON;
}

static void fan_sw_off(Switch* p_sw){
	(void)p_sw;
	FAN_SW_OFF;
	p_sw->state = SW_ST_OFF;
}

static void charger_sw_on(Switch* p_sw){
	(void)p_sw;
	//CHARGER_SW_ON;
	SET_CHARGER_STATE = HIGH;
	p_sw->state = SW_ST_ON;
}

static void charger_sw_off(Switch* p_sw){
	(void)p_sw;
	//CHARGER_SW_OFF;
	SET_CHARGER_STATE = LOW;
	p_sw->state = SW_ST_OFF;
}

static void standby_led_sw_on(Switch* p_sw){
	(void)p_sw;
	//LED_R_LOW;
	SET_LED_R_STATE = LOW;
	//LED_G_LOW;
	SET_LED_G_STATE = LOW;
	//LED_B_HIGH;
	SET_LED_B_STATE = HIGH;
}

static void standby_led_sw_off(Switch* p_sw){
	(void)p_sw;
	SET_LED_R_STATE = HIGH;
	SET_LED_G_STATE = LOW;
	SET_LED_B_STATE = LOW;
	//LED_B_LOW;
	//LED_G_LOW;
	//LED_R_HIGH;
}

static void rs485_slave_sync_data_serialize_impl(RS485_Slave* p_485s){
	char* buff = (char*)p_485s->tx_data;
	*buff++=':';
	buff+=long_to_string(slave_address, buff);
	*buff++=',';
	*buff++=selex_bss_app.base.csv.cc;
	*buff++=',';
	buff+=long_to_string(!door_state, buff);
	*buff++=',';
	buff+=long_to_string(selex_bss_app.fan.state, buff);
	*buff++=',';
	buff+=long_to_string(selex_bss_app.node_id_pin.state, buff);
	*buff++=',';
	buff+=long_to_string(selex_bss_app.sw_charge.state, buff);
	*buff++=',';
	buff+=long_to_string(selex_bss_app.temp_ss->temp, buff);
	*buff++='*';
	*buff++='\0';
}


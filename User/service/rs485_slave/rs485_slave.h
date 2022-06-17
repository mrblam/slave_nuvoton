/*
 * rs485_slave.h
 *
 *  Created on: May 12, 2021
 *      Author: KhanhDinh
 */

#ifndef SERVICE_RS485_SLAVE_RS485_SLAVE_H_
#define SERVICE_RS485_SLAVE_RS485_SLAVE_H_

#include "stdlib.h"
#include "string_util.h"
#include "string.h"
#include "uart_hw.h"

#define DELIMITER_CHARACTER	","

typedef enum MASTER_CC{
	MASTER_WRITE = 'W',
	MASTER_READ = 'R',
	MASTER_IDLE = '\0'
}MASTER_CC;

typedef enum SLAVE_OBJS{
	SLAVE_DOOR = 'D',
	SLAVE_FAN = 'F',
	SLAVE_NODE_ID = 'N',
	SLAVE_CHARGER = 'C',
	SLAVE_LED = 'L'
}SLAVE_OBJS;

typedef enum SLAVE_STATE{
	ACTIVE = 1,
	INACTIVE = 0
}SLAVE_STATE;

typedef struct RS485_csv_data_t RS485_csv_data;
struct RS485_csv_data_t{
	uint8_t 		slave_id;
	MASTER_CC		cc;
	SLAVE_OBJS		obj;
	SLAVE_STATE 	state;
};

typedef enum RS485_SLAVE_STATE{
	RS485_SLAVE_ST_IDLE,
	RS485_SLAVE_ST_WAIT_SYNC,
	RS485_SLAVE_ST_SUCCESS,
	RS485_SLAVE_ST_FAIL
} RS485_SLAVE_STATE;

typedef struct RS485_Slave_t RS485_Slave;
typedef void (*RS485_act)(RS485_Slave* p_485s);
struct RS485_Slave_t{
	UART_hw*			p_hw;
	RS485_SLAVE_STATE	state;
	uint8_t				rx_data[20];
	uint8_t				rx_index;
	uint8_t*			start_msg;
	uint8_t 			tx_data[20];
	RS485_act			check_master_command;
	RS485_act			sync_data_serialize;
	RS485_csv_data		csv;
	uint32_t			timeout;
	uint8_t 			is_new_msg;
};

void rs485_slave_process(RS485_Slave* p_485s, uint32_t timestamp);
void rs485_slave_response_msg_serialize(RS485_Slave* p_485s);
void rs485_slave_reset_buffer(RS485_Slave* p_485s);
uint8_t rs485_slave_check_valid_msg(RS485_Slave* p_485s, uint8_t* buff);
void rs485_sends(RS485_Slave* p_485s);

#endif /* SERVICE_RS485_SLAVE_RS485_SLAVE_H_ */

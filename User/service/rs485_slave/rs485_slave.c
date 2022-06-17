
/*
 * rs485_slave.h
 *
 *  Created on: May 12, 2021
 *      Author: KhanhDinh
 */

#include "rs485_slave.h"

static void rs485_parse_data(RS485_Slave* p_485s);

void rs485_slave_process(RS485_Slave* p_485s, uint32_t timestamp){
	switch(p_485s->state){
	case RS485_SLAVE_ST_IDLE:
		if(p_485s->is_new_msg){
			rs485_parse_data(p_485s);
			p_485s->check_master_command(p_485s);
			p_485s->timeout = timestamp + 500;
			p_485s->is_new_msg = 0;
		}
		break;
	case RS485_SLAVE_ST_WAIT_SYNC:
		if(p_485s->is_new_msg){
			rs485_parse_data(p_485s);
			p_485s->check_master_command(p_485s);
			p_485s->is_new_msg = 0;
			return;
		}
		if(p_485s->timeout < timestamp){
			p_485s->state = RS485_SLAVE_ST_FAIL;
			return;
		}
		break;
	case RS485_SLAVE_ST_SUCCESS:
		rs485_slave_reset_buffer(p_485s);
		p_485s->state = RS485_SLAVE_ST_IDLE;
		break;
	case RS485_SLAVE_ST_FAIL:
        rs485_slave_reset_buffer(p_485s);
		p_485s->state = RS485_SLAVE_ST_IDLE;
		break;
	default:
		break;
	}
}

void rs485_slave_response_msg_serialize(RS485_Slave* p_485s){
	char* buff = (char*)p_485s->tx_data;
	*buff++=':';
	buff+=long_to_string(p_485s->csv.slave_id, buff);
	*buff++=',';
	*buff++=p_485s->csv.cc;
	*buff++=',';
	*buff++=p_485s->csv.obj;
	*buff++='*';
	*buff++='\0';
}

void rs485_slave_reset_buffer(RS485_Slave* p_485s){
	for(uint8_t i = 0; i<20; i++){
		p_485s->rx_data[i] = 0;
		p_485s->tx_data[i] = 0;
	}
	p_485s->rx_index = 0;
}

uint8_t rs485_slave_check_valid_msg(RS485_Slave* p_485s, uint8_t* buff){
	buff += p_485s->rx_index-1;
	while((*buff != '*') || (*buff != '\0')){
		if(*buff == '*'){
			*buff = '\0';
			buff--;
			while((*buff != ':') || (*buff != '\0')){
				if(*buff == ':'){
					p_485s->start_msg = ++buff;
					return 1;
				}
				else if(*buff == '\0') return 0;
				buff--;
			}
		}
		else if(*buff == '\0') return 0;
		buff--;
	}
	return 0;
}

void rs485_sends(RS485_Slave* p_485s){
	EN_RS485_HIGH;
	uart_sends(p_485s->p_hw, p_485s->tx_data);
	EN_RS485_LOW;
	p_485s->csv.cc = MASTER_IDLE;
}

static void rs485_parse_data(RS485_Slave* p_485s){
	if(rs485_slave_check_valid_msg(p_485s, p_485s->rx_data)){
		p_485s->is_new_msg = 0;
		char* token = strtok((char*)p_485s->start_msg, DELIMITER_CHARACTER);
		p_485s->csv.slave_id = string_to_long(token);
		if(p_485s->csv.slave_id == slave_address){
			token = strtok(NULL, DELIMITER_CHARACTER);
			p_485s->csv.cc = (MASTER_CC)*token;
			token = strtok(NULL, DELIMITER_CHARACTER);
			p_485s->csv.obj = (SLAVE_OBJS)*token;
			token = strtok(NULL, DELIMITER_CHARACTER);
			p_485s->csv.state = (SLAVE_STATE)string_to_long(token);
		}
		else rs485_slave_reset_buffer(p_485s);
	}
	else rs485_slave_reset_buffer(p_485s);
}

/*
 * uart_hw.h
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#ifndef BOARD_UART_HW_UART_HW_H_
#define BOARD_UART_HW_UART_HW_H_

#include "stdlib.h"
#include "cabinet_slave_hw.h"
#include "NuMicro.h"
typedef struct UART_hw_t UART_hw;

struct UART_hw_t{
	uint8_t rx_data;
	void (*receive_handle)(UART_hw* p_hw);
};

extern UART_hw uart;

#define BAUD_RATE			115200

void uart_hw_init(void);
void uart_sends(UART_hw* p_hw, uint8_t* s);

#endif /* BOARD_UART_HW_UART_HW_H_ */

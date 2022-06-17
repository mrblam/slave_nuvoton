/*
 * board.h
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#ifndef BOARD_H_
#define BOARD_H_


#include "core_hw.h"
#include "adc_hw.h"
#include "cabinet_slave_hw.h"
#include "uart_hw.h"



void board_init(void);
void disable_interrupts();
void enable_interrupts();
#endif /* BOARD_H_ */

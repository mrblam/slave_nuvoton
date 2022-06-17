/*
 * core_hw.h
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#ifndef BOARD_NUVOTON_CORE_HW_H_
#define BOARD_NUVOTON_CORE_HW_H_

#include <stdio.h>
#include "NuMicro.h"

#define SYSTEM_TICK_ms				10
//#define SYSTEM_TICK_PRESCALER		TIM2_PRESCALER_256
//#define SYSTEM_TICK_PERIOD			(16000000/TIM2_PRESCALER_256/SYSTEM_TICK_ms/10)

void core_hw_init(void);

#endif /* BOARD_CORE_HW_CORE_HW_H_ */

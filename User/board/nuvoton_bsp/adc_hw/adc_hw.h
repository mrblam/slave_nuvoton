/*
 * adc_hw.h
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#ifndef BOARD_ADC_HW_ADC_HW_H_
#define BOARD_ADC_HW_ADC_HW_H_

#include "stdlib.h"
#include "stdint.h"

typedef struct ADC_hw_t ADC_hw;
struct ADC_hw_t{
	uint32_t	adc_value;
	int32_t 	adc_offset;
	void 		(*get_adc_value)(ADC_hw* p_hw);
};

extern ADC_hw ntc;

void adc_hw_init(void);

#endif /* BOARD_ADC_HW_ADC_HW_H_ */

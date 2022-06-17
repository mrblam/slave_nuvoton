/*
 * ntc.h
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#ifndef COMPONENTS_NTC_NTC_H_
#define COMPONENTS_NTC_NTC_H_

#include "stdlib.h"
#include "stdint.h"
#include "adc_sensor.h"
#include "app_config.h"

#define NTC_RESISTOR	10000
#define MIN_TEMP		0
#define MAX_TEMP		100
#define LUT_SIZE		(MAX_TEMP - MIN_TEMP + 1)

typedef struct NTC_t NTC;
typedef void (*ntc_act)(NTC* p_ntc);

struct NTC_t{
	ADC_Sensor base;
	const uint16_t* lut;
	uint16_t lut_size;
	int16_t min_temp;
	int16_t max_temp;
	int16_t temp;
	uint32_t impedance;
	ntc_act update_impedance;
};

NTC* ntc_construct(void);

static inline void ntc_update_impedance(NTC* p_ntc){
	p_ntc->update_impedance(p_ntc);
}

static inline uint16_t ntc_get_impedance(const NTC* const p_ntc){
	return p_ntc->impedance;
}

static inline void ntc_set_lut(NTC* p_ntc,const uint16_t* const p_lut){
	p_ntc->lut=p_lut;
}

static inline int16_t ntc_get_temp(const NTC* const p_ntc){
	return p_ntc->temp;
}

void ntc_update_temp(NTC* p_ntc);

#endif /* COMPONENTS_NTC_NTC_H_ */

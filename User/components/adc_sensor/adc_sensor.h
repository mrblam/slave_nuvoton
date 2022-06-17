/*
 * adc_sensor.h
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#ifndef COMPONENTS_ADC_SENSOR_ADC_SENSOR_H_
#define COMPONENTS_ADC_SENSOR_ADC_SENSOR_H_

#include "adc_hw.h"
#include "app_config.h"

typedef struct ADC_Sensor_t ADC_Sensor;

struct ADC_Sensor_t{
	ADC_hw* 	hw;
	uint32_t 	result;
	uint8_t 	gain;
	void (*update_result)(ADC_Sensor* p_ss);
};

void adc_sensor_init(ADC_Sensor* p_ss);

static inline uint32_t adc_sensor_get_result(const ADC_Sensor* const p_ss){
	return p_ss->result;
}

static inline void adc_sensor_update_result(ADC_Sensor* p_ss){
	p_ss->update_result(p_ss);
}

#endif /* COMPONENTS_ADC_SENSOR_ADC_SENSOR_H_ */

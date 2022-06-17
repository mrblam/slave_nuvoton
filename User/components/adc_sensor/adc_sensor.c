/*
 * adc_sensor.c
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#include "adc_sensor.h"

static void adc_sensor_update_result_default_impl(ADC_Sensor* p_ss);

void adc_sensor_init(ADC_Sensor* p_ss){
	p_ss->hw = &ntc;
	p_ss->hw->adc_offset = -20;
	p_ss->gain = 1;
	p_ss->update_result=adc_sensor_update_result_default_impl;
}

static void adc_sensor_update_result_default_impl(ADC_Sensor* p_ss){
	//p_ss->result = 5*p_ss->hw->adc_value;
	p_ss->result = (VREF0*(p_ss->hw->adc_value - p_ss->hw->adc_offset))* p_ss->gain/ADC_RESOLUTION;
}



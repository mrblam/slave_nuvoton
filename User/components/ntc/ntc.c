/*
 * ntc.c
 *
 *  Created on: May 4, 2021
 *      Author: KhanhDinh
 */

#include "ntc.h"

static void ntc_update_impedance_handle(NTC* p_ntc);

NTC* ntc_construct(void){
	NTC* p_ntc = (NTC*)malloc(sizeof(NTC));
	while(p_ntc == NULL);
	adc_sensor_init((ADC_Sensor*)p_ntc);
	p_ntc->min_temp = MIN_TEMP;
	p_ntc->max_temp = MAX_TEMP;
	p_ntc->lut_size = LUT_SIZE;
	p_ntc->update_impedance = ntc_update_impedance_handle;
	return p_ntc;
}

static void ntc_update_impedance_handle(NTC* p_ntc){
	adc_sensor_update_result((ADC_Sensor*)p_ntc);
	if(p_ntc->base.result){
		p_ntc->impedance = (uint32_t)(NTC_RESISTOR*p_ntc->base.result)/(VREF0 - p_ntc->base.result);
	}
}

static int16_t ntc_get_temp_from_impedance(const uint16_t impedance,const uint16_t* const p_lut,
		const uint16_t size,const int16_t min){

	int16_t id=0;
    while((impedance < p_lut[id]) &&(id<size)){
   	 id++;
    }
	return(id+min);
}

void ntc_update_temp(NTC* p_ntc){

	ntc_update_impedance(p_ntc);

	p_ntc->temp=ntc_get_temp_from_impedance(p_ntc->impedance,p_ntc->lut,p_ntc->lut_size,
			p_ntc->min_temp);
}



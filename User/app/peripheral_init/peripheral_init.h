/*
 * peripheral_init.h
 *
 *  Created on: Jun 1, 2022
 *      Author: hoanpx
 */

#ifndef USER_APP_PERIPHERAL_INIT_PERIPHERAL_INIT_H_
#define USER_APP_PERIPHERAL_INIT_PERIPHERAL_INIT_H_
#include "cabinet_slave_app.h"

extern Cabinet_slave_app	selex_bss_app;

void peripheral_init(Cabinet_slave_app* p_app);
void ntc_init(NTC* p_ntc);


#endif /* USER_APP_PERIPHERAL_INIT_PERIPHERAL_INIT_H_ */

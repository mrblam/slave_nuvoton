/*
 * board.c
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#include "board.h"
//void core_hw_init(void);

void board_init(void){
	core_hw_init();
	cabinet_slave_hw_init();
	adc_hw_init();



	/* uart init*/
     uart_hw_init();
    /* Lock protected registers */

    /* Update System Core Clock */
     SystemCoreClockUpdate();

     SYS_LockReg();


}
void disable_interrupts(){
	/* disable UART */
	NVIC_DisableIRQ(UART0_IRQn);

	/* disable sys tick*/

	/* disable timer */

}
void enable_interrupts(){
	/* enable UART */
	NVIC_EnableIRQ(UART0_IRQn);

	/* enable sys tick*/

	/* enable timer */

	/* enable systick */
	NVIC_EnableIRQ(TMR0_IRQn);


}




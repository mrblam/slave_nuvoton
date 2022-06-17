/*
 * uart_hw.c
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#ifndef BOARD_UART_HW_UART_HW_C_
#define BOARD_UART_HW_UART_HW_C_

#include "uart_hw.h"

UART_hw uart;

void uart_hw_init(void){

	 /* Enable UART0 clock */
	    CLK_EnableModuleClock(UART0_MODULE);



	    /* Switch UART0 clock source to HIRC */
	    CLK_SetModuleClock(UART0_MODULE, CLK_CLKSEL1_UART0SEL_HIRC, CLK_CLKDIV0_UART0(1));




	 /* Set PB multi-function pins for UART0 RXD=PB.7 and TXD=PC.6 */
	    SYS->GPB_MFP1 = (SYS->GPB_MFP1 & ~(SYS_GPB_MFP1_PB7MFP_Msk)) |        \
	                    (SYS_GPB_MFP1_PB7MFP_UART0_RXD);
	    SYS->GPC_MFP1 = (SYS->GPC_MFP1 & ~(SYS_GPC_MFP1_PC6MFP_Msk)) |        \
	                     (SYS_GPC_MFP1_PC6MFP_UART0_TXD);

	    /* Lock protected registers */
	    SYS_LockReg();

	    /* Init UART0 for printf and test */
	    SYS_ResetModule(UART0_RST);

	    /* Configure UART0 and set UART0 baud rate */
	    UART_Open(UART0, 115200);

	    NVIC_EnableIRQ(UART0_IRQn);
	    UART_EnableInt(UART0,UART_INTEN_RDAIEN_Msk);


	/* Enable UART1 Receive Interrupt */
//	UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
//	UART1_Cmd(ENABLE);
//	ITC_SetSoftwarePriority(ITC_IRQ_UART1_RX, ITC_PRIORITYLEVEL_2);
}

void uart_sends(UART_hw* p_hw, uint8_t* s){
#if 0
	while(*s){
		UART1_SendData8(*s);
		for(uint32_t cnt = 0; cnt < 100; cnt++);
		s++;
	}
#endif
	if(*s){
		//strlen(s);
		UART_Write(UART0, s, strlen(s));

	}
}

void UART0_IRQHandler(void)
{

	if (UART_GET_INT_FLAG(UART0,UART_INTSTS_RDAINT_Msk))
	{
		uart.rx_data = UART_READ(UART0);
		if((uart.receive_handle != NULL) && (uart.rx_data != '\0'))
		{
			uart.receive_handle(&uart);
		}
	}
}

#endif /* BOARD_UART_HW_UART_HW_C_ */

/*
 * core_hw.c
 *
 *  Created on: May 1, 2021
 *      Author: KhanhDinh
 */

#include "core_hw.h"
#include "app_config.h"

static void system_clock_init(void);
static void system_tick_init(void);

void core_hw_init(void){
	system_clock_init();
	system_tick_init();
}

static void system_clock_init(void){
	/* Unlock protected registers */
	    SYS_UnlockReg();

	    /* Enable HIRC clock (Internal RC 48MHz) */
	    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);

	    /* Wait for HIRC clock ready */
	    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);

	    /* Select HCLK clock source as HIRC and HCLK source divider as 1 */
	    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));

	    /* Set both PCLK0 and PCLK1 as HCLK/2 */
	    CLK->PCLKDIV = (CLK_PCLKDIV_APB0DIV_DIV2 | CLK_PCLKDIV_APB1DIV_DIV2);
#if 0
	    /* Set both PCLK0 and PCLK1 as HCLK */
	    CLK->PCLKDIV = CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1;
#endif
}

static void system_tick_init(void){
	/* Enable IP clock */
#if 1
	    	CLK_EnableModuleClock(TMR0_MODULE);
	    	CLK_SetModuleClock(TMR0_MODULE, CLK_CLKSEL1_TMR0SEL_HIRC, 0);
	   // TIMER_Open(TIMER0, TIMER_TOGGLE_MODE, 1000);
	   //TIMER_Open(TIMER0, TIMER_CONTINUOUS_MODE, 1000);
	    //TIMER_Open(TIMER0, TIMER_ONESHOT_MODE, 1000);
	    //TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 1000); //1 interrup per second
	    	TIMER_Open(TIMER0, TIMER_PERIODIC_MODE, 1000);
	        CLK_SysTickDelay(50);
	        /* Enable timer wake up system */
	        TIMER_EnableWakeup(TIMER0);
	        CLK_SysTickDelay(50);
	        /* Enable Timer0 interrupt */
	        TIMER_EnableInt(TIMER0);
	        CLK_SysTickDelay(50);
	        NVIC_EnableIRQ(TMR0_IRQn);
	        /* Start Timer0 counting */
	        TIMER_Start(TIMER0);
	        CLK_SysTickDelay(50);


#endif
}




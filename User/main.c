
#include "board.h"
#include "peripheral_init.h"
#include "string_util.h"
#include "cabinet_slave_app.h"
#include "app_config.h"


Cabinet_slave_app	selex_bss_app;

static uint32_t sys_timestamp = 0;
static uint16_t blink_time_interval_ms = 500;
static uint16_t stable_cnt;
//static uint8_t door_state1;

static void rs485_slave_check_master_command(RS485_Slave* p_485s);
static void update_door_state(Cabinet_slave_app* p_app);
static void led_update_state(Cabinet_slave_app* p_app);

static void uart_receive_handle_impl(UART_hw* p_uart){
	if(uart.rx_data == '*'){
		selex_bss_app.base.is_new_msg = 1;
	}
	if((selex_bss_app.base.rx_index < 20) && (uart.rx_data != 0)){
		selex_bss_app.base.rx_data[selex_bss_app.base.rx_index] = uart.rx_data;
		selex_bss_app.base.rx_index++;
	}
	else selex_bss_app.base.rx_index = 0;
}


int main(void){
	/* disable interrupt*/
	//disable_interrupts();

	/* board init*/
	board_init();
	peripheral_init(&selex_bss_app);

	selex_bss_app.base.p_hw = &uart;
	selex_bss_app.base.rx_index = 0;
	selex_bss_app.base.state = RS485_SLAVE_ST_IDLE;
	selex_bss_app.base.check_master_command = rs485_slave_check_master_command;
	uart.receive_handle = uart_receive_handle_impl;

	slave_address = 5;

	while(1);

}

/* System_Tick IRQ Handler ~ 1ms */

void TMR0_IRQHandler(void)
{
	sys_timestamp+= 1;
	blink_time_interval_ms--;
//	if(GET_DOOR_STATE == 1){
//		door_state1 = 1;
//	}
//	if(GET_DOOR_STATE == 0){
//		door_state1 = 0;
//	}
	door_state1 = GET_DOOR_STATE;
	rs485_slave_process((RS485_Slave*)&selex_bss_app, sys_timestamp);

	update_door_state(&selex_bss_app);
	cab_slave_app_update_temp(&selex_bss_app, sys_timestamp);
	if(blink_time_interval_ms == 0){
		blink_led(&selex_bss_app.cabinet_led, sys_timestamp);
		blink_time_interval_ms = 100;
	}

	TIMER_ClearIntFlag(TIMER0);
	//TIM2_ClearITPendingBit(TIM2_IT_UPDATE);
}
#if 0
void UART0_IRQHandler(void)
{
	//
	uint8_t u8InChar = 0xFF;

	    if (UART_GET_INT_FLAG(UART0,UART_INTSTS_RDAINT_Msk))
	    {
	        printf("\nInput:");
//	        SYS_ResetModule(UART0_RST);
//	        UART_ClearIntFlag(UART0, (UART_INTSTS_RLSINT_Msk| UART_INTSTS_BUFERRINT_Msk | UART_INTSTS_SWBEINT_Msk| UART_INTSTS_MODEMINT_Msk| UART_INTEN_WKIEN_Msk| UART_INTSTS_LININT_Msk));
//	        UART_Open(UART0, 115200);
//	        NVIC_EnableIRQ(UART0_IRQn);
//	         UART_EnableInt(UART0,UART_INTEN_RDAIEN_Msk); /// UART_INTEN_RXTOIEN_Msk
	        UART0->FIFO |= UART_FIFO_RXRST_Msk;
	    }
	if (UART_GET_INT_FLAG(UART0,UART_INTSTS_RDAINT_Msk))
	{

		selex_bss_app.base.rx_index++;
	}
		if(uart.rx_data == '*'){
		selex_bss_app.base.is_new_msg = 1;
	}
	if((selex_bss_app.base.rx_index < 20) && (uart.rx_data != 0)){
		selex_bss_app.base.rx_data[selex_bss_app.base.rx_index] = uart.rx_data;
		selex_bss_app.base.rx_index++;
	}
	else selex_bss_app.base.rx_index = 0;
}
#endif
static void rs485_slave_check_master_command(RS485_Slave* p_485s){
	if(p_485s->csv.cc == MASTER_WRITE){
		switch(p_485s->csv.obj){
		case SLAVE_DOOR:
			sw_off(&selex_bss_app.node_id_pin);
			sw_off(&selex_bss_app.sw_charge);
			sw_off(&selex_bss_app.fan);
			sw_on(&selex_bss_app.door);
			selex_bss_app.cabinet_led.blink_state++;
			selex_bss_app.cabinet_led.blink_time_ms = 5000;
			break;
		case SLAVE_NODE_ID:
			sw_process(&selex_bss_app.node_id_pin, p_485s->csv.state);
			break;
		case SLAVE_CHARGER:
			sw_process(&selex_bss_app.sw_charge, p_485s->csv.state);
			sw_process(&selex_bss_app.fan, selex_bss_app.sw_charge.state);
			break;
		case SLAVE_FAN:
			sw_process(&selex_bss_app.fan, p_485s->csv.state);
			break;
		case SLAVE_LED:
			if((LED_COLOR)p_485s->csv.state == BLINK){
				selex_bss_app.cabinet_led.blink_state++;
				selex_bss_app.cabinet_led.blink_time_ms = 5000;
				return;
			}
			led_set_color(&selex_bss_app.cabinet_led, (LED_COLOR)p_485s->csv.state);
			break;
		default:
			break;
		}
		rs485_slave_response_msg_serialize(p_485s);
		p_485s->state = RS485_SLAVE_ST_WAIT_SYNC;
		rs485_sends(p_485s);

	}
	else if(p_485s->csv.cc == MASTER_READ){
		p_485s->sync_data_serialize(p_485s);
		rs485_sends(p_485s);
		p_485s->state = RS485_SLAVE_ST_SUCCESS;
	}
}

static void update_door_state(Cabinet_slave_app* p_app){
	if(door_state != GET_DOOR_STATE){
		stable_cnt++;
		if(stable_cnt == 500){
			stable_cnt = 0;
			door_state = GET_DOOR_STATE;
			led_update_state(p_app);
		}
	}
	else stable_cnt = 0;

	if(p_app->sw_charge.state == SW_ST_ON) return;
	if(p_app->fan.state == SW_ST_OFF) return;
	sw_off(&p_app->fan);
}

static void led_update_state(Cabinet_slave_app* p_app){
	if(door_state == SW_ST_OFF){
		selex_bss_app.cabinet_led.color = RED;
		led_set_color(&selex_bss_app.cabinet_led, RED);
	}
	else{
		if(selex_bss_app.node_id_pin.state == SW_ST_ON) sw_off(&selex_bss_app.node_id_pin);
		selex_bss_app.cabinet_led.color = BLUE;
		led_set_color(&selex_bss_app.cabinet_led, BLUE);
	}

	selex_bss_app.cabinet_led.blink_state++;
	selex_bss_app.cabinet_led.blink_time_ms = 5000;
}





/* -------------------------------------------------------------------------------- */

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif




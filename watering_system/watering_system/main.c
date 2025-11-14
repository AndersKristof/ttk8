/*
 * watering_system.c
 *
 * Created: 14.11.2025 12:08:43
 * Author : ankristo
 */ 

#define F_CPU 2000000

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "clkctrl.h"
#include "uart.h"
#include "adc.h"
#include "relay.h"

uint16_t baud = 833;

int main(void)
{
	clkctrl_init();
	uart_init(baud);
	adc_init();
	relay_init();
	
	PORTF_DIRSET = PIN5_bm;
	   
	int i = 0;
	uint8_t adc_result;
	int8_t moisture_result_in_percent;
	   
    while (1) 
    {
		uart_send_number(i);
		i++;
		uart_send_string(". result: ");
		
		
		adc_result = adc_get_result();
		moisture_result_in_percent = abs((100*adc_result/255)-100);
		uart_send_number(moisture_result_in_percent);
		
		uart_send_string("%\n\r");
		
		PORTF_OUTTGL = PIN5_bm;
		relay_on();
		_delay_ms(1000);
		relay_off();
		_delay_ms(1000);
		
    }
}


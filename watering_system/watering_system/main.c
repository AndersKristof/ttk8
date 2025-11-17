/*
 * main.c
 *
 * Application entry for the automatic watering controller. Initializes
 * hardware modules (clock, UART, ADC, relay, sleep control) and runs
 * the main sampling loop that logs ADC values and triggers watering.
 */

#define F_CPU 2000000

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>

#include "clkctrl.h"
#include "uart.h"
#include "adc.h"
#include "relay.h"
#include "config.h"
#include "moisture_sensor.h"

uint8_t moisture_level_in_percent;

ISR(USART3_RXC_vect)
{
	uint8_t byte_received = uart_receive_byte();
	
	if (byte_received == 't')
	{
		uart_send_string("Received UART signal: 't'\n\rToggling relay.\n\r");
		relay_toggle();
	} 
	else if (byte_received == 'r')
	{
		uart_send_string("Received UART signal: 'r'\n\rRunning one watering sequence.\n\r");
		relay_on();
		_delay_ms(WATER_DURATION_MS);
		relay_off();
	}
	else if (byte_received == 'c')
	{
		uart_send_string("Received UART signal: 'c'\n\rChecking current moisture level.\n\r");
		
		moisture_level_in_percent = 100*abs(adc_get_result() - 255)/255;
		uart_send_string("Current Moisture: ");
		uart_send_number(moisture_level_in_percent);
		uart_send_string("\n\r");
	}
	else {
		uart_send_string("Received UART signal: ");
		uart_send_byte(byte_received);
		uart_send_string("\n\rUnknown Command.\n\r");
	}
}

int main(void)
{
	clkctrl_init();
	moisture_sensor_init();
	adc_init();
	relay_init();
	
	if (TEST_MODE_ACTIVE)
	{
		uart_init(UART_BAUD_REGISTER_VALUE);
		sei();
		
		while (1);
	}
	else
	{
		while (1)
		{
			moisture_level_in_percent = 100*abs(adc_get_result() - 255)/255;
			
			if ((moisture_level_in_percent < MOISTURE_THRESHOLD_PERCENT) && !TEST_MODE_ACTIVE)
			{
				relay_on();
				_delay_ms(WATER_DURATION_MS);
				relay_off();
			}
			
			_delay_ms(SAMPLE_INTERVAL_MS);
			
		}
	}
}


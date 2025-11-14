/*
 * uart.c
 *
 * Created: 14.11.2325 12:22:25
 *  Author: ankristo
 */ 

#include <avr/io.h>
#include <string.h>
#include <stdio.h>

#include "uart.h"

void uart_init(uint16_t baud)
{
	USART3_BAUD = baud;
	USART3_CTRLC = (USART_CMODE_ASYNCHRONOUS_gc | USART_PMODE_DISABLED_gc | USART_SBMODE_1BIT_gc | USART_CHSIZE_8BIT_gc);
	PORTB_DIRSET = PIN0_bm; // Set PB0 (TxD) as OUTPUT
	USART3_CTRLB = USART_TXEN_bm; // Enable Transmitter
}

void uart_send_byte(uint8_t byte)
{
	USART3_TXDATAL = byte;
	while(!(USART3_STATUS & USART_DREIF_bm));
}

void uart_send_string(char string[])
{
	int i = 0;
	while (string[i] != 0x00)
	{
		uart_send_byte(string[i]);
		i++;
	}
}

void uart_send_number(int number)
{
	char buffer[100];
	sprintf(buffer, "%d", number);
	uart_send_string(buffer);
}
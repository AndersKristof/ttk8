/*
 * uart.h
 *
 * Created: 14.11.2025 12:21:08
 *  Author: ankristo
 */ 


#ifndef UART_H_
#define UART_H_

void uart_init(uint16_t baud);
void uart_send_byte(uint8_t byte);
void uart_send_string(char string[]);
void uart_send_number(int number);
uint8_t uart_receive_byte();

#endif /* UART_H_ */
/*
 * uart.h
 *
 * Simple UART transmit/receive API for logging and basic command I/O.
 * The implementation exposes initialization and byte/string helpers.
 */


#ifndef UART_H_
#define UART_H_

void uart_init(uint16_t baud);
void uart_send_byte(uint8_t byte);
void uart_send_string(char string[]);
void uart_send_number(int number);
uint8_t uart_receive_byte();

#endif /* UART_H_ */
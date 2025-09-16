#include "uart.h"

void uart_init(void) {
	UBRRH = (uint8_t)(UBRR_VALUE >> 8);
	UBRRL = (uint8_t)UBRR_VALUE;
	
	UCSRB = (1 << TXEN);
	
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void uart_transmit(uint8_t data) {

	while (!(UCSRA & (1 << UDRE)));
	UDR = data;
}

uint8_t uart_receive(void) {

	while (!(UCSRA & (1 << RXC)));
	return UDR;
}

bool uart_data_available(void) {
	return (UCSRA & (1 << RXC)) != 0;
}

bool uart_transmit_ready(void) {
	return (UCSRA & (1 << UDRE)) != 0;
}

#include "uart.h"

void uart_init(void) {

	UBRRH = (uint8_t)(UBRR_VALUE >> 8);
	UBRRL = (uint8_t)UBRR_VALUE;

	UCSRB = (1 << RXEN) | (1 << RXCIE);
	
	// Set frame format: 8 data bits, 1 stop bit, no parity
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

void uart_rx_interrupt_handler(void) {

	g_system_status.distance = UDR;
}


ISR(USART_RXC_vect) {
	uart_rx_interrupt_handler();
}

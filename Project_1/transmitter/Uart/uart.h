#ifndef UART_H
#define UART_H

#include "system_config.h"

#define UBRR_VALUE ((F_CPU/16/BAUD_RATE) - 1)

void uart_init(void);
void uart_transmit(uint8_t data);
uint8_t uart_receive(void);
bool uart_data_available(void);
bool uart_transmit_ready(void);

#endif // UART_H
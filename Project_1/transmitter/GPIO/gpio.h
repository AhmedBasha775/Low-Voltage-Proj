#ifndef GPIO_H
#define GPIO_H

#include "system_config.h"

void gpio_init(void);
void trigger_pin_high(void);
void trigger_pin_low(void);
void trigger_pulse(void);
bool read_echo_pin(void);

#endif // GPIO_H
#ifndef GPIO_H
#define GPIO_H

#include "system_config.h"

void gpio_init(void);
void led_on(void);
void led_off(void);
void led_toggle(void);
void buzzer_on(void);
void buzzer_off(void);
void buzzer_toggle(void);
void all_outputs_off(void);

#endif // GPIO_H
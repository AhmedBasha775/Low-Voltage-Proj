#ifndef TIMER_H
#define TIMER_H

#include "system_config.h"


#define TIMER_PRESCALER     64
#define TIMER_FREQUENCY_HZ  1000  
#define OCR1A_VALUE         ((F_CPU / (TIMER_PRESCALER * TIMER_FREQUENCY_HZ)) - 1)


void timer_init(void);
void timer_start(void);
void timer_stop(void);
uint32_t timer_get_milliseconds(void);


void timer_interrupt_handler(void);

#endif // TIMER_H
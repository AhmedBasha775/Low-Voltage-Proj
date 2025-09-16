#ifndef TIMER_H
#define TIMER_H

#include "system_config.h"

#define TIMER_PRESCALER_8       (1 << CS11)
#define TIMER_PRESCALER_NONE    0

void timer_init(void);
void timer_start_measurement(void);
void timer_stop_measurement(void);
uint16_t timer_get_count(void);
void timer_reset_count(void);
uint32_t timer_get_milliseconds(void);

#endif // TIMER_H
#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "system_config.h"
#include "gpio.h"
#include "timer.h"

void ultrasonic_init(void);
void ultrasonic_trigger_measurement(void);
bool ultrasonic_wait_for_measurement(uint16_t timeout_ms);
uint16_t ultrasonic_get_raw_duration(void);
bool ultrasonic_is_measurement_complete(void);
void ultrasonic_reset_measurement(void);

void ultrasonic_echo_interrupt_handler(void);

#endif // ULTRASONIC_H
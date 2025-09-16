#ifndef COLLISION_CONTROL_H
#define COLLISION_CONTROL_H

#include "system_config.h"
#include "gpio.h"
#include "timer.h"


void collision_control_init(void);
void collision_control_process(void);
void collision_control_update_led(void);
void collision_control_update_buzzer(void);
void collision_control_handle_safe_distance(void);
void collision_control_handle_warning_distance(void);

#endif // COLLISION_CONTROL_H
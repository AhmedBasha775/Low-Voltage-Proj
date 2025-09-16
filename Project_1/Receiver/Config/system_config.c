#include "system_config.h"


volatile system_status_t g_system_status = {
	.distance = 255,        
	.led_state = false,
	.buzzer_state = false,
	.led_counter = 0,
	.buzzer_counter = 0,
	.buzzer_period = 0
};

void system_init(void) {

	g_system_status.distance = 20;
	g_system_status.led_state = false;
	g_system_status.buzzer_state = false;
	g_system_status.led_counter = 0;
	g_system_status.buzzer_counter = 0;
	g_system_status.buzzer_period = 0;
}
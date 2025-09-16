#include "collision_control.h"

void collision_control_init(void) {
	g_system_status.led_counter = 0;
	g_system_status.buzzer_counter = 0;
	g_system_status.buzzer_period = 0;
}

void collision_control_process(void) {
	if (g_system_status.distance <= DISTANCE_THRESHOLD) {
		collision_control_handle_warning_distance();
		} else {
		collision_control_handle_safe_distance();
	}
}

void collision_control_handle_warning_distance(void) {
	// Calculate buzzer period based on distance
	g_system_status.buzzer_period = BUZZER_TIME_MULTIPLIER * g_system_status.distance;
	
	// Update LED and buzzer states
	collision_control_update_led();
	collision_control_update_buzzer();
}

void collision_control_handle_safe_distance(void) {
	// Turn off all warning indicators
	all_outputs_off();
	
	g_system_status.led_counter = 0;
	g_system_status.buzzer_counter = 0;
}

void collision_control_update_led(void) {
	static uint32_t last_led_toggle_time = 0;
	uint32_t current_time = timer_get_milliseconds();
	
	if (current_time - last_led_toggle_time >= LED_TOGGLE_PERIOD_MS) {
		led_toggle();
		last_led_toggle_time = current_time;
	}
}

void collision_control_update_buzzer(void) {
	static uint32_t last_buzzer_toggle_time = 0;
	uint32_t current_time = timer_get_milliseconds();
	
	if (g_system_status.buzzer_period > 0) {
		// Toggle buzzer based on calculated period (50% duty cycle)
		if (current_time - last_buzzer_toggle_time >= g_system_status.buzzer_period) {
			buzzer_toggle();
			last_buzzer_toggle_time = current_time;
		}
	}
}
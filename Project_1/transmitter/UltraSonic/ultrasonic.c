#include "ultrasonic.h"

void ultrasonic_init(void) {

	MCUCR |= (1 << ISC00);
	MCUCR &= ~(1 << ISC01);

	GICR |= (1 << INT0);
	

	ultrasonic_reset_measurement();
}

void ultrasonic_trigger_measurement(void) {

	ultrasonic_reset_measurement();
	
	trigger_pulse();
	

	g_ultrasonic_status.measurement_start_time = timer_get_milliseconds();
}

bool ultrasonic_wait_for_measurement(uint16_t timeout_ms) {
	uint32_t start_time = timer_get_milliseconds();
	
	while (!g_ultrasonic_status.measurement_complete) {

		if ((timer_get_milliseconds() - start_time) >= timeout_ms) {
			return false; 
		}
		

		_delay_us(10);
	}
	
	return true;  
}

uint16_t ultrasonic_get_raw_duration(void) {
	return g_ultrasonic_status.echo_duration;
}

bool ultrasonic_is_measurement_complete(void) {
	return g_ultrasonic_status.measurement_complete;
}

void ultrasonic_reset_measurement(void) {
	g_ultrasonic_status.echo_duration = 0;
	g_ultrasonic_status.measurement_complete = false;
	g_ultrasonic_status.echo_received = false;
}

void ultrasonic_echo_interrupt_handler(void) {
	if (read_echo_pin()) {

		timer_start_measurement();
		g_ultrasonic_status.echo_received = true;
		} else {

		if (g_ultrasonic_status.echo_received) {
			timer_stop_measurement();
			g_ultrasonic_status.echo_duration = timer_get_count();
			g_ultrasonic_status.measurement_complete = true;
		}
	}
}


ISR(INT0_vect) {
	ultrasonic_echo_interrupt_handler();
}
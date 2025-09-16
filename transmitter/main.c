#include "system_config.h"
#include "uart.h"
#include "gpio.h"
#include "timer.h"
#include "ultrasonic.h"
#include "distance_calculator.h"

int main(void) {
	system_init();
	uart_init();
	gpio_init();
	timer_init();
	ultrasonic_init();
	
	// Enable global interrupts
	sei();
	
	uint8_t measured_distance;
	
	while (1) {
		// Trigger ultrasonic measurement
		ultrasonic_trigger_measurement();
		
		// Wait for measurement completion or timeout
		if (ultrasonic_wait_for_measurement(MEASUREMENT_TIMEOUT_MS)) {
			// Calculate distance from measurement
			measured_distance = distance_calculator_get_distance();
			} else {

			measured_distance = DISTANCE_ERROR_VALUE;
		}
		
		// Transmit distance via UART
		uart_transmit(measured_distance);
		
		// Wait before next measurement
		_delay_ms(MEASUREMENT_INTERVAL_MS);
	}
	
	return 0;
}
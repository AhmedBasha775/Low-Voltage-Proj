#include "system_config.h"
#include "uart.h"
#include "gpio.h"
#include "timer.h"
#include "collision_control.h"

int main(void) {
	// Initialize all system modules
	system_init();
	uart_init();
	gpio_init();
	timer_init();
	collision_control_init();
	
	// Enable global interrupts
	sei();
	
	// Main application loop
	while (1) {
		// Process collision avoidance logic
		collision_control_process();
		
		// Small delay to prevent excessive CPU usage
		_delay_ms(10);
	}
	
	return 0;
}

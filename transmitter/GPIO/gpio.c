#include "gpio.h"

void gpio_init(void) {

	TRIG_DDR |= (1 << TRIG_PIN);
	trigger_pin_low();  
	

	ECHO_DDR &= ~(1 << ECHO_PIN);
	ECHO_PORT |= (1 << ECHO_PIN);  
}

void trigger_pin_high(void) {
	TRIG_PORT |= (1 << TRIG_PIN);
}

void trigger_pin_low(void) {
	TRIG_PORT &= ~(1 << TRIG_PIN);
}

void trigger_pulse(void) {
	trigger_pin_high();
	_delay_us(TRIGGER_PULSE_WIDTH_US);
	trigger_pin_low();
}

bool read_echo_pin(void) {
	return (ECHO_PIN_INPUT & (1 << ECHO_PIN)) != 0;
}
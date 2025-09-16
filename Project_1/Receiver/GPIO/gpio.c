#include "gpio.h"

void gpio_init(void) {
	// Set LED and buzzer pins as output
	LED_DDR |= (1 << LED_PIN);
	BUZZER_DDR |= (1 << BUZZER_PIN);
	
	// Initially turn off all outputs
	all_outputs_off();
}

void led_on(void) {
	LED_PORT |= (1 << LED_PIN);
	g_system_status.led_state = true;
}

void led_off(void) {
	LED_PORT &= ~(1 << LED_PIN);
	g_system_status.led_state = false;
}

void led_toggle(void) {
	LED_PORT ^= (1 << LED_PIN);
	g_system_status.led_state = !g_system_status.led_state;
}

void buzzer_on(void) {
	BUZZER_PORT |= (1 << BUZZER_PIN);
	g_system_status.buzzer_state = true;
}

void buzzer_off(void) {
	BUZZER_PORT &= ~(1 << BUZZER_PIN);
	g_system_status.buzzer_state = false;
}

void buzzer_toggle(void) {
	BUZZER_PORT ^= (1 << BUZZER_PIN);
	g_system_status.buzzer_state = !g_system_status.buzzer_state;
}

void all_outputs_off(void) {
	led_off();
	buzzer_off();
}
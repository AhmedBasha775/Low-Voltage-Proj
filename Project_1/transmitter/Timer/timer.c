#include "timer.h"

static volatile uint32_t millisecond_counter = 0;

void timer_init(void) {

	TCCR1A = 0;
	TCCR1B = 0;
	
	TCNT1 = 0;
	
	TCCR0 = (1 << WGM01) | (1 << CS02) | (1 << CS00);  
	OCR0 = 7;  
	TIMSK |= (1 << OCIE0);  
}

void timer_start_measurement(void) {
	TCNT1 = 0;  
	TCCR1B = TIMER_PRESCALER_8;  
}

void timer_stop_measurement(void) {
	TCCR1B = TIMER_PRESCALER_NONE;  
}

uint16_t timer_get_count(void) {
	return TCNT1;
}

void timer_reset_count(void) {
	TCNT1 = 0;
}

uint32_t timer_get_milliseconds(void) {
	return millisecond_counter;
}


ISR(TIMER0_COMP_vect) {
	millisecond_counter++;
}
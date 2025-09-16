#include "timer.h"

static volatile uint32_t millisecond_counter = 0;

void timer_init(void) {
	// Configure Timer1 for CTC mode with appropriate prescaler
	TCCR1B = (1 << WGM12) | (1 << CS11) | (1 << CS10); 
	
	// Set compare value for 1ms interrupts
	OCR1A = OCR1A_VALUE;
	
	// Enable Timer1 compare match A interrupt
	TIMSK |= (1 << OCIE1A);
	
	// Reset counter
	millisecond_counter = 0;
}

void timer_start(void) {

	TIMSK |= (1 << OCIE1A);
}

void timer_stop(void) {
	TIMSK &= ~(1 << OCIE1A);
}

uint32_t timer_get_milliseconds(void) {
	return millisecond_counter;
}

void timer_interrupt_handler(void) {
	millisecond_counter++;
}


ISR(TIMER1_COMPA_vect) {
	timer_interrupt_handler();
}

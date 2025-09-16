#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

#define F_CPU 8000000UL  
#define BAUD_RATE 9600

#define TRIG_PORT       PORTC
#define TRIG_DDR        DDRC
#define TRIG_PIN        PC0

#define ECHO_PORT       PORTD
#define ECHO_DDR        DDRD
#define ECHO_PIN        PD2
#define ECHO_PIN_INPUT  PIND


#define MEASUREMENT_INTERVAL_MS     100   
#define MEASUREMENT_TIMEOUT_MS      30    
#define DISTANCE_ERROR_VALUE        255   
#define TRIGGER_PULSE_WIDTH_US      10    

#define SOUND_SPEED_CM_US           0.0343f  
#define TIMER_TICK_TO_US            1.0f     

typedef struct {
	volatile uint16_t echo_duration;
	volatile bool measurement_complete;
	volatile bool echo_received;
	uint32_t measurement_start_time;
} ultrasonic_status_t;

extern volatile ultrasonic_status_t g_ultrasonic_status;


void system_init(void);

#endif // SYSTEM_CONFIG_H
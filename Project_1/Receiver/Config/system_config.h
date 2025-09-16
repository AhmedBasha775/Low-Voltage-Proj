#ifndef SYSTEM_CONFIG_H
#define SYSTEM_CONFIG_H

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>

#define F_CPU 8000000UL  
#define BAUD_RATE 9600


#define LED_PORT        PORTB
#define LED_DDR         DDRB
#define LED_PIN         PB0

#define BUZZER_PORT     PORTB
#define BUZZER_DDR      DDRB
#define BUZZER_PIN      PB1


#define LED_TOGGLE_PERIOD_MS    500  // LED toggles every 500ms
#define DISTANCE_THRESHOLD      50   // Distance threshold in cm
#define BUZZER_TIME_MULTIPLIER  10   // Buzzer period = distance * 10ms


typedef struct {
	uint8_t distance;
	bool led_state;
	bool buzzer_state;
	uint16_t led_counter;
	uint16_t buzzer_counter;
	uint16_t buzzer_period;
} system_status_t;

extern volatile system_status_t g_system_status;

void system_init(void);

#endif // SYSTEM_CONFIG_H
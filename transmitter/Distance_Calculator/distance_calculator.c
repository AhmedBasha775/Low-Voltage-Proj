#include "distance_calculator.h"


uint8_t distance_calculator_get_distance(void) {
	if (ultrasonic_is_measurement_complete()) {
		uint16_t raw_duration = ultrasonic_get_raw_duration();
		return distance_calculator_raw_to_cm(raw_duration);
		} else {
		return DISTANCE_ERROR_VALUE;
	}
}

uint8_t distance_calculator_raw_to_cm(uint16_t raw_duration) {
	// Calculate distance using the formula:
	// Distance = (echo_time * sound_speed) / 2
	//
	// With timer prescaler 8 at 8MHz: 1 tick = 1µs
	// Sound speed = 343 m/s = 0.0343 cm/µs
	// Distance in cm = (raw_duration * 0.0343) / 2
	
	uint32_t distance_cm = ((uint32_t)raw_duration * 343UL) / 20000UL;
	
	if (distance_cm < MIN_DISTANCE_CM) {
		distance_cm = MIN_DISTANCE_CM;
		} else if (distance_cm > MAX_DISTANCE_CM) {
		distance_cm = MAX_DISTANCE_CM;
	}
	
	return (uint8_t)distance_cm;
}

bool distance_calculator_is_valid_distance(uint8_t distance) {
	return (distance >= MIN_DISTANCE_CM) &&
	(distance <= MAX_DISTANCE_CM) &&
	(distance != DISTANCE_ERROR_VALUE);
}
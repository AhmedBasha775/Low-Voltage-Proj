#ifndef DISTANCE_CALCULATOR_H
#define DISTANCE_CALCULATOR_H

#include "system_config.h"
#include "ultrasonic.h"


#define MIN_DISTANCE_CM     2
#define MAX_DISTANCE_CM     400

uint8_t distance_calculator_get_distance(void);
uint8_t distance_calculator_raw_to_cm(uint16_t raw_duration);
bool distance_calculator_is_valid_distance(uint8_t distance);

#endif // DISTANCE_CALCULATOR_H
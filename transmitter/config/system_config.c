#include "system_config.h"

volatile ultrasonic_status_t g_ultrasonic_status = {
	.echo_duration = 0,
	.measurement_complete = false,
	.echo_received = false,
	.measurement_start_time = 0
};

void system_init(void) {

	g_ultrasonic_status.echo_duration = 0;
	g_ultrasonic_status.measurement_complete = false;
	g_ultrasonic_status.echo_received = false;
	g_ultrasonic_status.measurement_start_time = 0;
}

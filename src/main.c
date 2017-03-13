#include <initialisation/clock_config.h>
#include <initialisation/gpio_config.h>
#include <initialisation/uart_config.h>
#include <initialisation/timer_config.h>
#include <initialisation/exti_config.h>

#include <drivers/actuators/ax12/ax12.h>
#include <drivers/actuators/motion/motion.h>
#include <drivers/sensors/colour/colour.h>


#include "tasks/task_test_1.h"
#include "tasks/task_test_2.h"
#include "core/task_mngr.h"

void main(void)
{
	clock_config();
	gpio_config();
	exti_config();
	uart_config();
	timer_config();

	ctor_test_1();
	ctor_test_2();

	reset_driver();
	set_motion_speed(40);

	state.status=IDLE_MOTION;
//	task_mngr_run();
	goto_xy(500, 0, 1);
	goto_xy(500, 500, 1);

	while (1) {
		gpio_toggle(RED_LED);
		delay(16800000);
		if (state.status==IDLE_MOTION){
			debug("IDLE");
		}
		else if (state.status==MOVING){
			debug("MOVING");
		}
		else debug("RANDOM");

	}



}

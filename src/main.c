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
#include "executors/front_rollers/front_rollers.h"

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
	set_motion_speed(100);

//	task_mngr_run();


	while (1) {
		rollers_forward();
		delay(100000000);
		rollers_off();
		delay(100000000);
		rollers_reverse();
		delay(100000000);
		rollers_off();
		delay(100000000);
	}



}

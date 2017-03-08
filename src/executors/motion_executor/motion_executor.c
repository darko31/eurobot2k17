#include "motion_executor.h"
#include "../colour_shifter/colour_shifter.h"


void tim7_isr(void)
{

	if (timer_get_flag(TIM7, TIM_SR_UIF)) {

		read_status_and_position();

		colour_shift_count();

		/* Clear overflow interrupt flag. */
		timer_clear_flag(TIM7, TIM_SR_UIF);

	}

}

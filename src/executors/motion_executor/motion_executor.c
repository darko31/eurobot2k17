#include "motion_executor.h"
#include "../colour_shifter/colour_shifter.h"


void tim7_isr(void)
{

	if (timer_get_flag(TIM7, TIM_SR_UIF))
	{

		read_status_and_position();
		//check_goal();
		moving_delay++;

		colour_shift_count();

		gpio_toggle(GPIOD, GPIO15);

		/* Clear overflow interrupt flag. */
		timer_clear_flag(TIM7, TIM_SR_UIF);

	}

}

void check_goal(){


	if (((state.x >= state_desired.x + HITBOX) || (state.x <= state_desired.x - HITBOX))
		&& ((state.y >= state_desired.y + HITBOX) || (state.y <= state_desired.y - HITBOX)))
	{
		goto_xy_continue(state_desired.x, state_desired.y, 1);
		hard_stop_flag=0;

	}

}

void set_current_positon(){

	state.x=state_desired.x;
	state.y=state_desired.y;
	state.orientation=state_desired.orientation;
}

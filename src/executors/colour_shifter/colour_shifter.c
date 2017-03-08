#include "colour_shifter.h"

uint8_t enable_colour_shifter=0;
volatile uint16_t colour_shifter_count=0;
colour_enum_t current_colour, colour_desired;

void enable_colour_shift(colour_enum_t colour)
{
	enable_colour_shifter=1;
	colour_desired=colour;
}

void colour_shift(void)
{
	current_colour=read_colour();

	if (colour_desired == BLUE){

		if (current_colour == YELLOW){
			ax12_set_speed(COLOUR_SHIFTER_ID, 0);
			enable_colour_shifter=0;
		}
	}

	else if (colour_desired == YELLOW){

		if (current_colour == BLUE){
			ax12_set_speed(COLOUR_SHIFTER_ID, 0);
			enable_colour_shifter=0;
			}
		}

	else ax12_set_speed(COLOUR_SHIFTER_ID, 100);

}

void colour_shift_count(void)
{
	if (enable_colour_shifter>0){
		colour_shifter_count++;

		if (colour_shifter_count>COLOUR_SHIFTER_COUNT){
			colour_shift();
			colour_shifter_count=0;
		}
	}

}

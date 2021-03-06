#include "timer_config.h"
#include "gpio_config.h"


static void timer1_config(void)
{
	/* Servo 8 (TIM_OC1) output */
	timer_reset(TIM1);
	timer_set_prescaler(TIM1, 52);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM1, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	timer_enable_preload(TIM1);
	timer_continuous_mode(TIM1);
	timer_set_period(TIM1, 16000);
	/* Output compare mode: timer identifier, channel identifier == 1, mode == regular PWM */
	timer_disable_oc_output(TIM1, TIM_OC1);
	timer_set_oc_mode(TIM1, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_value(TIM1, TIM_OC1, 100);
	/* Enable PWM */
	timer_enable_oc_output(TIM1, TIM_OC1);
	timer_enable_break_main_output(TIM1);
	timer_enable_counter(TIM1);
}

static void timer2_config(void)
{
	/* Servo 7 (TIM_OC1) output */
	/* Configured for DC motor, 1 kHz */ 
	timer_reset(TIM2);
	timer_set_prescaler(TIM2, 26);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM2, TIM_CR1_CKD_CK_INT_MUL_2, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier == 2, channel identifier, mode == regular PWM */
	timer_set_oc_mode(TIM2, TIM_OC1, TIM_OCM_PWM1);
	timer_set_period(TIM2, 800);
	timer_set_oc_value(TIM2, TIM_OC1, 0);
	/* Enable PWM */
	timer_enable_oc_output(TIM2, TIM_OC1);
	timer_enable_counter(TIM2);
}

static void timer3_config(void)
{
	/* Servo 5 (TIM_OC2) and Servo 6 (TIM_OC1) output */
	timer_reset(TIM3);
	timer_set_prescaler(TIM3, 26);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 3, mode == regular PWM */
	timer_set_oc_mode(TIM3, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_mode(TIM3, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_enable_oc_output(TIM3, TIM_OC1);
	timer_enable_oc_output(TIM3, TIM_OC2);
	timer_enable_break_main_output(TIM3);
	timer_set_period(TIM3, 16000);
	timer_set_oc_value(TIM3, TIM_OC1, 100);
	timer_set_oc_value(TIM3, TIM_OC2, 100);
	timer_enable_counter(TIM3);
}

static void timer4_config(void)
{
	/*Servo 4 (TIM_OC2) output */
	timer_reset(TIM4);
	timer_set_prescaler(TIM4, 26);
	/* Timer mode: timer identifier, clock division == 1, alignment, direction */
	timer_set_mode(TIM4, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 4, mode == regular PWM */
	timer_set_oc_mode(TIM4, TIM_OC2, TIM_OCM_PWM1);
	timer_set_period(TIM4, 16000);
	timer_set_oc_value(TIM4, TIM_OC2, 100);
	/* Enable PWM */
	timer_enable_oc_output(TIM4, TIM_OC2);
	timer_enable_counter(TIM4);
}

static void timer6_config(void)
{
	timer_reset(TIM6);
	timer_set_prescaler(TIM6, 420);
	timer_set_period(TIM6, 100);
	timer_enable_update_event(TIM6);
	timer_enable_irq(TIM6, TIM_DIER_UIE);
	timer_enable_counter(TIM6);
}

/* Timer 7 interrupt, used for getting status from motion driver, set to 10 ms */

static void timer7_config(void)
{
	timer_reset(TIM7);
	timer_set_prescaler(TIM7, 420);
	timer_set_period(TIM7, 1000);
	timer_enable_update_event(TIM7);
	timer_enable_irq(TIM7, TIM_DIER_UIE);
	timer_enable_counter(TIM7);
	nvic_enable_irq(NVIC_TIM7_IRQ);
	timer_enable_irq(TIM7, TIM_DIER_UIE);
}

static void timer9_config(void)
{
	/* Servo 1 (TIM_OC2) and Servo 2 (TIM_OC1) outputs */
	timer_reset(TIM9);
	timer_set_prescaler(TIM9, 105);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM9, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 9, mode == regular PWM */
	timer_set_oc_mode(TIM9, TIM_OC1, TIM_OCM_PWM1);
	timer_set_oc_mode(TIM9, TIM_OC2, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_set_period(TIM9, 16000);
	timer_set_oc_value(TIM9, TIM_OC1, 100);
	timer_set_oc_value(TIM9, TIM_OC2, 100);
	timer_enable_oc_output(TIM9, TIM_OC1);
	timer_enable_oc_output(TIM9, TIM_OC2);
	//timer_enable_break_main_output(TIM9);
	timer_enable_counter(TIM9);
}

static void timer10_config(void)
{
	/* Should be Servo 3 (TIMOC1) output, I (Darko) missed a pin, my bad, useless currently */
	timer_reset(TIM10);
	timer_set_prescaler(TIM10, 0);
	/* Timer mode: timer identifier, clock division == 0, alignment, direction */
	timer_set_mode(TIM10, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	/* Output compare mode: timer identifier, channel identifier == 10, mode == regular PWM */
	timer_set_oc_mode(TIM10, TIM_OC1, TIM_OCM_PWM1);
	/* Enable PWM */
	timer_set_period(TIM10, 8399);
	timer_set_oc_value(TIM10, TIM_OC1, 8000);
	timer_enable_oc_output(TIM10, TIM_OC1);
	timer_enable_counter(TIM10);
}

/* Configured as external counter for color sensnor */

static void timer12_config(void)
{
	timer_reset(TIM12);
	timer_set_prescaler(TIM12, 0);
	timer_set_mode(TIM12, TIM_CR1_CKD_CK_INT, TIM_CR1_CMS_CENTER_1, TIM_CR1_DIR_UP);
	timer_set_period(TIM12, 10000);
	timer_slave_set_mode(TIM12, TIM_SMCR_SMS_ECM1);
	timer_slave_set_trigger(TIM12, TIM_SMCR_TS_TI2FP2);
	timer_ic_set_prescaler(TIM12, TIM_IC2, 0);
	timer_ic_set_filter(TIM12, TIM_IC2, TIM_IC_OFF);
	timer_ic_set_input(TIM12, TIM_IC2, TIM_IC_IN_TI2);
	timer_ic_enable(TIM12, TIM_IC2);
	timer_enable_counter(TIM12);
}

void timer_config(void)
{
	timer1_config();
	timer2_config();
	timer3_config();
	timer4_config();
	timer6_config();
	timer7_config();
	timer9_config();
	timer10_config();
	timer12_config();
}

void delay(uint32_t clocks){

	for (uint32_t i=0; i<clocks; i++){
		__asm__("nop");
	}
}

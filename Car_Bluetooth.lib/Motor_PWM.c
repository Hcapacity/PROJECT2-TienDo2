#include "Motor_PWM.h"

void PWM_Set_Duty(MOTOR_HandleTypdef* MOTOR_Type, uint8_t speed){
	uint32_t CCR = MOTOR_Type->htim->Instance->ARR*(100 - speed)/100;
	switch(MOTOR_Type->Channel){
		case TIM_CHANNEL_1:
			MOTOR_Type->htim->Instance->CCR1 = CCR;
			break;
		case TIM_CHANNEL_2:
			MOTOR_Type->htim->Instance->CCR2 = CCR;
			break;
		case TIM_CHANNEL_3:
			MOTOR_Type->htim->Instance->CCR3 = CCR;
			break;
		case TIM_CHANNEL_4:
			MOTOR_Type->htim->Instance->CCR4 = CCR;
			break;
	}
}


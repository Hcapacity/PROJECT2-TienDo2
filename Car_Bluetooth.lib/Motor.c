#include "Motor.h"

void MOTOR_init(MOTOR_HandleTypdef* MOTOR_Type, TIM_HandleTypeDef* htim, uint32_t Channel, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin){
	MOTOR_Type->htim = htim;
	MOTOR_Type->Channel = Channel;
	MOTOR_Type->GPIOx = GPIOx,
	MOTOR_Type->GPIO_Pin = GPIO_Pin;
	HAL_TIM_PWM_Start(MOTOR_Type->htim, MOTOR_Type->Channel);
}
void MOTOR_Handle(MOTOR_STATE Mstate, MOTOR_HandleTypdef* MOTOR_Type, uint8_t speed){
	switch(Mstate){
		case STOP_STATE: 
			HAL_GPIO_WritePin(MOTOR_Type->GPIOx, MOTOR_Type->GPIO_Pin, GPIO_PIN_RESET);
		  PWM_Set_Duty(MOTOR_Type, 0);
			break;
		case CW_STATE:
			HAL_GPIO_WritePin(MOTOR_Type->GPIOx, MOTOR_Type->GPIO_Pin, GPIO_PIN_SET);
		  PWM_Set_Duty(MOTOR_Type, speed);
			break;
		case CCW_STATE:
			HAL_GPIO_WritePin(MOTOR_Type->GPIOx, MOTOR_Type->GPIO_Pin, GPIO_PIN_RESET);
		  PWM_Set_Duty(MOTOR_Type, speed);
			break;
		default:
			HAL_GPIO_WritePin(MOTOR_Type->GPIOx, MOTOR_Type->GPIO_Pin, GPIO_PIN_RESET);
		  PWM_Set_Duty(MOTOR_Type, 0);
			break;
	}
}


#ifndef MOTOR_PWM_H
#define MOTOR_PWM_H
#include "main.h"

typedef struct{
	TIM_HandleTypeDef* htim;
	uint32_t Channel;
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
} MOTOR_HandleTypdef;


void PWM_Set_Duty(MOTOR_HandleTypdef* MOTOR_Type, uint8_t speed);


#endif


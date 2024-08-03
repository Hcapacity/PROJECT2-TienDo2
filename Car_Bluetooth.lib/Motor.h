#ifndef MOTOR_H
#define MOTOR_H
#include "Motor_PWM.h"
typedef enum{
	STOP_STATE,
	CW_STATE, // theo chieu kim dong ho
	CCW_STATE // nguoc chieu kim dong ho
}MOTOR_STATE;

typedef enum{
	CAR_FORWARD,
	CAR_BACK,
	CAR_LEFT,
	CAR_RIGHT,
	CAR_STOP
}CAR_STATE;


void MOTOR_init(MOTOR_HandleTypdef* MOTOR_Type, TIM_HandleTypeDef* htim, uint32_t Channel, GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);
void MOTOR_Handle(MOTOR_STATE Mstate, MOTOR_HandleTypdef* MOTOR_Type, uint8_t speed);



#endif


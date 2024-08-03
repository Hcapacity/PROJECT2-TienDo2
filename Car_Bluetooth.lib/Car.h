#ifndef CAR_H
#define CAR_H
#include "Motor.h"


void CAR_init(TIM_HandleTypeDef* htim,char enable, MOTOR_HandleTypdef* MOTOR_FR_Type, MOTOR_HandleTypdef* MOTOR_FL_Type, 
	MOTOR_HandleTypdef* MOTOR_BR_Type, MOTOR_HandleTypdef* MOTOR_BL_Type, uint8_t speed);

void CAR_Handle(CAR_STATE carsta, char enable, MOTOR_HandleTypdef* MOTOR_FR_Type, MOTOR_HandleTypdef* MOTOR_FL_Type, 
	MOTOR_HandleTypdef* MOTOR_BR_Type, MOTOR_HandleTypdef* MOTOR_BL_Type, uint8_t speed);

#endif


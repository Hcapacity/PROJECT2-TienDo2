#include "Car.h"

void CAR_init(TIM_HandleTypeDef* htim,char enable, MOTOR_HandleTypdef* MOTOR_FR_Type, MOTOR_HandleTypdef* MOTOR_FL_Type, 
	MOTOR_HandleTypdef* MOTOR_BR_Type, MOTOR_HandleTypdef* MOTOR_BL_Type, uint8_t speed){
//------------- CAR STOP STATE --------------------------
	MOTOR_Handle(STOP_STATE, MOTOR_FR_Type, 0);
	MOTOR_Handle(STOP_STATE, MOTOR_FL_Type, 0);
	MOTOR_Handle(STOP_STATE, MOTOR_BR_Type, 0);
	MOTOR_Handle(STOP_STATE, MOTOR_BL_Type, 0);
	MOTOR_init(MOTOR_FR_Type, htim, TIM_CHANNEL_1, MOTOR_FR_IO_GPIO_Port, MOTOR_FR_IO_Pin);
	MOTOR_init(MOTOR_FL_Type, htim, TIM_CHANNEL_2, MOTOR_FL_IO_GPIO_Port, MOTOR_FL_IO_Pin);
	MOTOR_init(MOTOR_BR_Type, htim, TIM_CHANNEL_3, MOTOR_BR_IO_GPIO_Port, MOTOR_BR_IO_Pin);
	MOTOR_init(MOTOR_BL_Type, htim, TIM_CHANNEL_4, MOTOR_BL_IO_GPIO_Port, MOTOR_BL_IO_Pin);
	enable = 'x';
}

void CAR_Handle(CAR_STATE carsta, char enable, MOTOR_HandleTypdef* MOTOR_FR_Type, MOTOR_HandleTypdef* MOTOR_FL_Type, 
	MOTOR_HandleTypdef* MOTOR_BR_Type, MOTOR_HandleTypdef* MOTOR_BL_Type, uint8_t speed){
	if(enable == 'X'){
	switch(carsta){
		case CAR_FORWARD:
			MOTOR_Handle(CW_STATE, MOTOR_FR_Type, speed);
		  MOTOR_Handle(CCW_STATE, MOTOR_FL_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_BR_Type, speed);
		  MOTOR_Handle(CCW_STATE, MOTOR_BL_Type, speed);
			break;
		case CAR_BACK:
			MOTOR_Handle(CCW_STATE, MOTOR_FR_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_FL_Type, speed);
		  MOTOR_Handle(CCW_STATE, MOTOR_BR_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_BL_Type, speed);
			break;
		case CAR_LEFT:
			MOTOR_Handle(CW_STATE, MOTOR_FR_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_FL_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_BR_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_BL_Type, speed);
			break;
		case CAR_RIGHT:
			MOTOR_Handle(CCW_STATE, MOTOR_FR_Type, speed);
		  MOTOR_Handle(CCW_STATE, MOTOR_FL_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_BR_Type, speed);
		  MOTOR_Handle(CW_STATE, MOTOR_BL_Type, speed);
			break;
		case CAR_STOP:
			MOTOR_Handle(STOP_STATE, MOTOR_FR_Type, 0);
		  MOTOR_Handle(STOP_STATE, MOTOR_FL_Type, 0);
		  MOTOR_Handle(STOP_STATE, MOTOR_BR_Type, 0);
		  MOTOR_Handle(STOP_STATE, MOTOR_BL_Type, 0);
			break;
		default:
			MOTOR_Handle(STOP_STATE, MOTOR_FR_Type, 0);
		  MOTOR_Handle(STOP_STATE, MOTOR_FL_Type, 0);
		  MOTOR_Handle(STOP_STATE, MOTOR_BR_Type, 0);
		  MOTOR_Handle(STOP_STATE, MOTOR_BL_Type, 0);
			break;
	}
}
	
	else {
		MOTOR_Handle(STOP_STATE, MOTOR_FR_Type, 0);
		MOTOR_Handle(STOP_STATE, MOTOR_FL_Type, 0);
		MOTOR_Handle(STOP_STATE, MOTOR_BR_Type, 0);
		MOTOR_Handle(STOP_STATE, MOTOR_BL_Type, 0);
	}
}
	

/*
 * motor.h
 *
 *  Created on: Jul 15, 2024
 *      Author: Redaa
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
#define MOTOR_PORT_ID  PORTB_ID
#define MOTOR_PIN1_ID  PIN0_ID
#define MOTOR_PIN2_ID  PIN1_ID
#define TIMER_PORT_ID  PORTB_ID
#define TIMER_PIN_ID   PIN3_ID

typedef enum{
	Motor_State_Stop=0,
	Motor_State_CW ,
	Motor_State_CCW,
}DcMotor_State;


void DcMotor_Init(void);



void DcMotor_Rotate(DcMotor_State state,uint8 speed);


void PWM_Timer0_Start(uint8 duty_cycle);




#endif /* MOTOR_H_ */

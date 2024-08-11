/*
 * motor.c
 *
 *  Created on: Jul 15, 2024
 *      Author: Redaa
 */


#include"gpio.h"
#include"motor.h"
#include<avr/io.h>

GPIO_PinDirectionType direction=PIN_OUTPUT;



void PWM_Timer0_Start(uint8 duty_cycle){
	TCNT0 = 0; // Set Timer Initial Value to 0
	OCR0  = duty_cycle; //Set Compare value
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS01);
	GPIO_setupPinDirection(TIMER_PORT_ID, TIMER_PIN_ID, direction);


}
void DcMotor_Init(void){
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN1_ID,direction);
	GPIO_setupPinDirection(MOTOR_PORT_ID,MOTOR_PIN2_ID,direction);


	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_LOW);


}



void DcMotor_Rotate(DcMotor_State state,uint8 speed){
    uint8 duty_cycle = (uint8)((speed / 100.0) * 255);
	switch (state){
	case Motor_State_Stop:
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_LOW);
	break;
	case Motor_State_CW:
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_HIGH);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_LOW);
	PWM_Timer0_Start(duty_cycle);

	break;
	case Motor_State_CCW:
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN1_ID, LOGIC_LOW);
	GPIO_writePin(MOTOR_PORT_ID, MOTOR_PIN2_ID, LOGIC_HIGH);
	PWM_Timer0_Start(duty_cycle);
	break;
	}
}


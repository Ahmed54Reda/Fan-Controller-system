/*
 * main.c
 *
 *  Created on: Jul 15, 2024
 *      Author: Redaa
 */
#include "motor.h"
#include <util/delay.h>
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
int main(){
	ADC_ConfigType adc_config;
	adc_config.prescaler=ADC_PRESCALER_8;
	adc_config.ref_volt=ADC_REF_INTERNAL;
	LCD_clearScreen();
	DcMotor_Init();
	LCD_init();
	ADC_init(&adc_config);
	LCD_displayStringRowColumn(0,3,"Fan is ");
	DcMotor_State state;
	uint8 value;
	while(1)
	{
		LCD_displayStringRowColumn(1,3,"Temp =   C");
		value = LM35_getTemperature();
		if (value<30){
			state =Motor_State_Stop;
			DcMotor_Rotate(state,0);
			LCD_displayStringRowColumn(0,10,"OFF");
			_delay_ms(10);
			LCD_moveCursor(1,9);
			LCD_intgerToString(value);
			_delay_ms(10);


		}
		else if (value>30 && value <60){
			state =Motor_State_CW;
			DcMotor_Rotate(state,25);
			LCD_displayStringRowColumn(0,10,"ON ");
			_delay_ms(10);
			LCD_moveCursor(1,9);
			LCD_intgerToString(value);
			_delay_ms(10);
		}
		else if (value>60 && value <90){
			state =Motor_State_CW;
			DcMotor_Rotate(state,50);
			LCD_displayStringRowColumn(0,10,"ON ");
			_delay_ms(10);
			LCD_moveCursor(1,9);
			LCD_intgerToString(value);
			_delay_ms(10);
		}
		else if (value>90 && value <120){
			state =Motor_State_CW;
			DcMotor_Rotate(state,75);
			LCD_displayStringRowColumn(0,10,"ON ");
			_delay_ms(10);
			LCD_moveCursor(1,9);
			LCD_intgerToString(value);
			_delay_ms(10);
		}
		else{
			state =Motor_State_CW;
			DcMotor_Rotate(state,100);
			LCD_displayStringRowColumn(0,10,"ON ");
			_delay_ms(10);
			LCD_moveCursor(1,9);
			LCD_intgerToString(value);
			_delay_ms(10);
		}
//		LCD_moveCursor(1,3);
//		value = LM35_getTemperature();
//		LCD_intgerToString(value);


	}

	}



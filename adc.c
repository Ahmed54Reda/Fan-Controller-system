/*
 * ADC.c
 *
 *  Created on: Jul 11, 2024
 *      Author: Redaa
 */
#include"adc.h"
#include<avr/io.h>
#include"common_macros.h"

void ADC_init(const ADC_ConfigType * Config_Ptr) {

	ADCSRA|= (1<<ADEN);

	ADMUX =(ADMUX & 0x3F)|(Config_Ptr->ref_volt << 6);

	ADCSRA = (ADCSRA & 0xF8) |(Config_Ptr->prescaler);

}

uint16 ADC_readChannel(uint8 channel) {
	switch (channel) {

	case 0:
		channel &= CHANNEL_NUMBERS;
		ADMUX &=  ADC_REG_RESET;
		ADMUX |= CHANNEL_0;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 1:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_1;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 2:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_2;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 3:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_3;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 4:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_4;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 5:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_5;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 6:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_6;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	case 7:
		channel &= CHANNEL_NUMBERS;
		ADMUX &= ADC_REG_RESET;
		ADMUX |= CHANNEL_7;
		SET_BIT(ADCSRA, ADSC); /* Start conversion write '1' to ADSC */
		while (BIT_IS_CLEAR(ADCSRA, ADIF))
			; /* Wait for conversion to complete, ADIF becomes '1' */
		SET_BIT(ADCSRA, ADIF); /* Clear ADIF by write '1' to it :) */
		break;
	}
	return ADC;

}


/*
 * adc.h
 *
 *  Created on: Jul 11, 2024
 *      Author: Redaa
 */

#ifndef ADC_H_
#define ADC_H_
#include "std_types.h"
#define CHANNEL_NUMBERS 0x07 //Macro to be & with channel number to be sure that the input channel between 0 and 7
#define ADC_REG_RESET 0xE0
#define CHANNEL_0 0x00
#define CHANNEL_1 0x01
#define CHANNEL_2 0x02
#define CHANNEL_3 0x03
#define CHANNEL_4 0x04
#define CHANNEL_5 0x05
#define CHANNEL_6 0x06
#define CHANNEL_7 0x07
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


// Enumeration for ADC reference voltage
typedef enum {
    ADC_REF_AREF = 0,
    ADC_REF_AVCC = 1,
    ADC_REF_INTERNAL = 3
} ADC_ReferenceVoltage;

// Enumeration for ADC prescaler
typedef enum {
    ADC_PRESCALER_2 = 1,
    ADC_PRESCALER_4 = 2,
    ADC_PRESCALER_8 = 3,
    ADC_PRESCALER_16 = 4,
    ADC_PRESCALER_32 = 5,
    ADC_PRESCALER_64 = 6,
    ADC_PRESCALER_128 = 7
} ADC_Prescaler;


typedef struct{
 ADC_ReferenceVoltage ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

void ADC_init(const ADC_ConfigType * Config_Ptr);



uint16 ADC_readChannel(uint8 channel);








#endif /* ADC_H_ */

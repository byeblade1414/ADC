#ifndef _ADC_H_INCLUDED
#define _ADC_H_INCLUDED

#ifndef _AVR_ATMEGA32A_H_INCLUDED
#include <avr/io.h>
#endif

void adc_init();
uint8_t adc_conversion();


#endif
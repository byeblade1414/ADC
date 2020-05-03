#include "adc.h"

void adc_init()
{
	ADCSRA |= (1 << ADEN) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); // enable adc and set presacler to 128.
	ADMUX  |= (1 << REFS0); // AVCC with external capacitor at AREF pin. ADC0, left adjusted.
}

uint8_t adc_conversion()
{
	ADCSRA |= (1 << ADSC); // start adc conversion.
	//while((ADCSRA & (1 << ADSC)) != 0) // if adcs still set in adcsra register, wait it to finish its job.
	while(!(ADCSRA & (1<<ADIF))) // wait untill adif flag is set in adcsra, which is an alternative way of up.
	ADCSRA &= ~(1 << ADIF); // set adif flag to zero;
	return ADC;
}
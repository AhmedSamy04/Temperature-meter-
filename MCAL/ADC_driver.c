/*
 * ADC_Driver.c
 *
 * Created: 9/9/2022 7:25:56 PM
 *  Author: Ahmed Sami
 */ 


#include <avr/io.h>
#include "std_macros.h"
void ADC_vinit(void)
{
	SET_BIT(ADMUX,REFS0); //configure VREF
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADCSRA,ADEN); // enable ADC
	/* adjust ADC clock*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
}
unsigned short ADC_u16Read(void)
{
	unsigned short read_val;
	
	SET_BIT(ADCSRA,ADSC);
	while(IS_BIT_CLR(ADCSRA,ADIF));//stay in your position till ADIF become 1
	SET_BIT(ADCSRA,ADIF); // clear ADIF
	read_val=(ADCL);
	read_val|=(ADCH<<8);
	return read_val ;
}
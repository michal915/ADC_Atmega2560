/*
 * 		Project: ADC_mega_1
 * 		Board: Arduino Mega
 * 		Processor: Atmega 2056
 * 		Data: 4 lis 2013
 * 		Author: Michał Kielan
 *
 */

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <avr/iom2560.h>
#include <util/delay.h>
#include "HD44780/HD44780.h"

#define ADCIN PF5
#define LED PA0
#define DELAY 50
#define v_ref 5.00f


void ADC_Init(void);
void LCD_Init(void);

int main()  {

	ADC_Init();
	LCD_Init();

	 sei();

	while(1)  {

	}

}

void ADC_Init(void)	{

	ADCSRA |= (1<<ADEN);		//włączenie ADC
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);		//preskaler 128
	ADCSRA |= (1<<ADIE);		//włączenie przerwań
	ADCSRA |= (1<<ADSC);		//start konwersji
	ADCSRA |= (1<<ADATE);

	ADMUX |= (1<<REFS0);			// wewnetrzene napiecie uC - 5V
	ADMUX |= (1<<MUX2) | (1<<MUX0);		    // ADC input PF5 - ADC5 - analog_5

	DDRF &= ~(1<<ADCIN);		//ADCIN -> INPUT
	PORTF |= (1<<ADCIN);		//ADCIN -> pull-up
}


void LCD_Init(void)	{

	LCD_Initalize();
	LCD_Clear();
	LCD_GoTo(3,0);
	LCD_WriteText("ADC ISR");
}


ISR(ADC_vect)	{

	float v_in = (ADC*v_ref)/1024.0f;
	char volt_char[32];

    sprintf(volt_char,"U=%1.2fV",(double)v_in);

    LCD_GoTo(4,1);
	LCD_WriteText(volt_char);

  	  _delay_ms(50);
}


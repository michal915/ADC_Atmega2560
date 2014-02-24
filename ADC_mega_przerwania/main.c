/*
 * 		Project: ADC_mega_11
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

void ADC_Init(void);

int main()  {

	ADC_Init();

	 LCD_Initalize();
     LCD_Clear();
     LCD_Lightness(20);

	while(1)  {

	 ADCSRA |= (1<<ADSC);		//uruchomienie poj. konwersji
	      while(ADCSRA & (1<<ADSC));	//zakonczenie poj. konwersji

	       char ADC_char[32];
	   	   char volt_char[32];
	   	   float v_in;
	   	   const float v_ref = 5.00f;

	   		  v_in = (ADC*v_ref)/1024.0f;

	   	sprintf(ADC_char, "10bit=%d",ADC);
	        sprintf(volt_char,"U=%1.2fV",(double)v_in);

	   		      LCD_Clear();
	   	          LCD_GoTo(3,0);
	   	      	  LCD_WriteText("Pomiar ADC");
	   	      	  LCD_GoTo(4,1);
	   	      	  LCD_WriteText(volt_char);

      	  _delay_ms(50);
	}

}

void ADC_Init(void)	{

	ADCSRA |= (1<<ADEN);		//włączenie ADC
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);		//preskaler 128

//	ADMUX |= (1<<REFS1) | (1<<REFS0);	      //napiecie ref. zewnetrzne 2.56V
	ADMUX |= (1<<REFS0);			// wewnetrzene napiecie uC - 5V
	ADMUX |= (1<<MUX2) | (1<<MUX0);		    // ADC input PF5 - ADC5 - analog_5

	DDRF &= ~(1<<ADCIN);		//ADCIN -> INPUT
	PORTF |= (1<<ADCIN);		//ADCIN -> pull-up
}


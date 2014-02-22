//ADC_LCD
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/iom2560.h>
#include <util/delay.h>
#include "LCD/HD44780.h"

int main()  {

	ADCSRA |= (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
	ADMUX |= (1<<REFS0);

	char i[] = "Jakis tekst";

	LCD_Initalize();
	LCD_Clear();
	LCD_WriteText(i);


	while(1)  {

	}
}

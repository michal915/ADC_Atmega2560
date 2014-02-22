/*
 * 		Project: ADC
 * 		Board: DFRduino Romeo v1.0
 * 		Processor:	Atmega328P
 * 		Data: 4 lis 2013
 * 		Author: Michał Kielan
 *
 */
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define ADCIN PC5
#define LED PB5
#define DELAY 50

void ADC_Init(void);
void LED_Init(void);
void if_else(int *wsk_ADC);

    int main(void)
    {

      ADC_Init();
      LED_Init();


  while(1)
      {

        ADCSRA |= (1<<ADSC);		//uruchomienie poj. konwersji
        while(ADCSRA & (1<<ADSC));

        if_else(&ADC);


      }



    }

void ADC_Init(void)	{

	ADCSRA |= (1<<ADEN);		//włączenie ADC
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);	//preskaler 128

	ADMUX  |=  (1<<REFS1) | (1<<REFS0);	//napiecie ref 1.1
	ADMUX |= (1<<MUX2) | (1<<MUX0);		// ADC input PC5-ADC5

	DDRC |= 0x00;		//ADC -> INPUT
	PORTC |= 0xff;	//ADC -> pull-up

}



void LED_Init(void)	{

	DDRB |= 0xFF;		//LED -> OUTPUT

}



void if_else(int *wsk_ADC)	{

    if(*wsk_ADC<113)
      {

    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY);
      }
      else if(*wsk_ADC<226)
      {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+100);
      }

      else if(*wsk_ADC<339)
         {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+200);

         }

      else if(*wsk_ADC<452)
         {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+300);
         }

      else if(*wsk_ADC<565)
         {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+500);
         }

      else if(*wsk_ADC<678)
         {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+600);
         }

      else if(*wsk_ADC<791)
         {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+700);
         }

      else if(*wsk_ADC<904)
         {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+800);
         }

      else if(*wsk_ADC>905)
          {
    	  PORTB ^= (1<<LED);
    	  _delay_ms(DELAY+900);
            }

   }








//potencjometr
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/iom2560.h>

#define LED1 PA0
#define LED2 PA1
#define LED3 PA2
#define LED4 PA3
#define LED5 PA4
#define LED6 PA5

#define KEY PC0
#define ADCIN PF0

int  main(void)
{
  //Uruchomienie ADC, wewnętrzne napiecie odniesienia, tryb pojedynczej konwersji, preskaler 128, wejście PIN5, wynik do prawej
  ADCSRA =   (1<<ADEN) //ADEN: ADC Enable (uruchomienie przetwornika)

   //ADPS2:0: ustawienie preskalera, preskaler= 128
   |(1<<ADPS0)
   |(1<<ADPS1)
   |(1<<ADPS2);

  ADMUX  =  (1<<REFS1) | (1<<REFS0) //REFS1:0: Reference Selection Bits
         //Internal 2.56V Voltage Reference with external capacitor at AREF pin
    |(1<<MUX2) | (1<<MUX0); //Input Channel Selections (ADC5 - Pin 5 )

    DDRB  |= (1<<LED1)
		| (1<<LED2)
		| (1<<LED3)
		| (1<<LED4)
		| (1<<LED5)
		| (1<<LED6);

  DDRF=0xff;
  DDRC=0xff;                      //Nieużywane Piny na porcie C jako wyjścia
  DDRC  &=~ (1<<KEY);      		   //Ustawienie pinu klawisza jako wejście
  DDRF &=~ (1<<ADCIN);            //Ustawienie Wejścia ADC

  PORTC |=  (1<<KEY);      		   //Pull_up klawisz

  for(;;)//pętla główna
  {
    if(!(PINC & (1<<KEY)))			//jeśli klawisz wciśniety
    {
    ADCSRA |= (1<<ADSC); 			//ADSC: uruchomienie pojedynczej konwersji

    while(ADCSRA & (1<<ADSC)); //czeka na zakończenie konwersji

  if(ADC<140)//jeśli wynik ADC mniejszy od 350 gasi obydwie diody
  {
    PORTB  &=~ (1<<LED1);
    PORTB  &=~ (1<<LED2);
    PORTB  &=~ (1<<LED3);
    PORTB  &=~ (1<<LED4);
    PORTB  &=~ (1<<LED5);
    PORTB  &=~ (1<<LED6);
  }


  else if(ADC<280)
  {
	PORTB  |= (1<<LED1);
	PORTB  &=~ (1<<LED2);
	PORTB  &=~ (1<<LED3);
	PORTB  &=~ (1<<LED4);
	PORTB  &=~ (1<<LED5);
	PORTB  &=~ (1<<LED6);

  }

  else if(ADC<420)
   {
 	PORTB  |= (1<<LED1);
 	PORTB  |= (1<<LED2);
 	PORTB  &=~ (1<<LED3);
 	PORTB  &=~ (1<<LED4);
 	PORTB  &=~ (1<<LED5);
 	PORTB  &=~ (1<<LED6);

   }

  else if(ADC<560)
   {
 	PORTB  |= (1<<LED1);
 	PORTB  |= (1<<LED2);
 	PORTB  |= (1<<LED3);
 	PORTB  &=~ (1<<LED4);
 	PORTB  &=~ (1<<LED5);
 	PORTB  &=~ (1<<LED6);

   }

  else if(ADC<700)
   {
 	PORTB  |= (1<<LED1);
 	PORTB  |= (1<<LED2);
 	PORTB  |= (1<<LED3);
 	PORTB  |= (1<<LED4);
 	PORTB  &=~ (1<<LED5);
 	PORTB  &=~ (1<<LED6);

   }

  else if(ADC<840)
   {
 	PORTB  |= (1<<LED1);
 	PORTB  |= (1<<LED2);
 	PORTB  |= (1<<LED3);
 	PORTB  |=  (1<<LED4);
 	PORTB  |=  (1<<LED5);
 	PORTB  &=~ (1<<LED6);
   }

  else
   {
	PORTB  |= (1<<LED1);
	PORTB  |= (1<<LED2);
	PORTB  |= (1<<LED3);
	PORTB  |= (1<<LED4);
	PORTB  |= (1<<LED5);
	PORTB  |= (1<<LED6);
  }
    }
  }
}


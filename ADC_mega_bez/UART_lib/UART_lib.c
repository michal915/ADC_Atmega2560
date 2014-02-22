/*
 * UART_lib.c
 *
 *  Created on: 18 lis 2013
 *      Author: Michał Kielan
 *
 *      biblioteki UARTA do megi, wersja bez przerwań
 *      tryb 8 bit danych, 1 bit stopu, przy 9600 baudów jest ok,
 *      przy 115200 sie jebie i wywala krzaki, nie wiem czemu
 */

#include "UART_lib.h"


void USART_Init(unsigned int baud_rate)	{
	//uint16_t baud = ((CPU / baudrate * 16UL) -1);
	uint16_t baud = (16000000/16/baud_rate-1);

	UBRR0H = (uint8_t)(baud>>8);
	UBRR0L = (uint8_t)baud;

	UCSR0B = (1<<RXEN0) | (1<<TXEN0);

	UCSR0C = (1<<UMSEL01)  |(1<<UCSZ01)  | (1<<UCSZ00);
}



void USART_pub(unsigned char data)	{
	while(!(UCSR0A & (1<<UDRE0)));

	UDR0 = data;
}


unsigned char USART_sub(void)	{
	while(!(UCSR0A & (1<<UDRE0)));

	return UDR0;
}


void USART_publong(const char *s)	{

	while (*s)
			USART_pub(*s++);
}






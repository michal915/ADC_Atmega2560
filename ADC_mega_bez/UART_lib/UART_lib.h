/*
 * UART_lib.h
 *
 *  Created on: 18 lis 2013
 *      Author: Michał Kielan
 *
 *      biblioteki UARTA do megi, wersja bez przerwań
 *       tryb 8 bit danych, 1 bit stopu, przy 9600 baudów jest ok,
 *      przy 115200 sie jebie i wywala krzaki, nie wiem czemu
 */

#include <avr/io.h>
#include <avr/iom2560.h>

#define USART_BAUD 9600
//#define USART_BAUD 115200
#define CPU 16000000

#define __UBBR (((CPU/8/USART_BAUD))-1)
//#define __UBBR (((CPU/16/USART_BAUD))-1)

void USART_Init(unsigned int baud);
void USART_pub(unsigned char data);
void USART_put(const char *slowo);
unsigned char USART_sub(void);


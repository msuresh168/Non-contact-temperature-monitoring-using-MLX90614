/*
 * UART.c
 *
 * Created: 20-May-13 5:14:56 AM
 *  Author: Innovation
 */ 
#include <avr/io.h>


void uart_init()
{
	UCSRB |= ( 1 << TXEN )|( 1 << RXEN ); // UART TX ,RX enable
	UCSRC |= (1<<URSEL)|( 3<<UCSZ0 ); // asynchrones 8 ,parity none,1 stop bit
	UBRRH = 0;
	UBRRL = 51; /*  9600 Baud with 8MHz for Mega128 */
	
	
}

int uart_putc(unsigned char c)
{
	while (!(UCSRA & (1<<UDRE))); /* waits for possible sending */
	UDR = c; /* data send to indications */
	return 0;
}

char uart_getc()
{
	while (  !(UCSRA & (1 << RXC)));
	// Do nothing until data have been received and is ready to be read from UDR
	return(UDR); // return the byte
}

int uart_putstr(unsigned char *str)
{
	while(*str)
	uart_putc(*str++);
}

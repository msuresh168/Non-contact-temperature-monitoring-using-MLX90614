/*
 * UART.h
 *
 * Created: 20-May-13 5:15:21 AM
 *  Author: Innovation
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 8000000UL
void uart_init();
char uart_getc();
int uart_putc(unsigned char c);
int uart_putstr(unsigned char *str);



#endif /* UART_H_ */
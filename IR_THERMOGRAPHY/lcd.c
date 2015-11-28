// Program to interface LCD in 4 bit mode with AVR microcontroller
//#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<inttypes.h>

#include "lcd.h"



void lcd_init()	// fuction for intialize
{
	lcd_cmd(0x38);		//to initialize LCD in 2 lines, 5X7 dots and 4bit mode.
	lcd_cmd(0x0e);
	lcd_cmd(0x06);
	lcd_cmd(0x80);
}




void lcd_cmd(char cmd)
{
	PORTB=cmd;
	PORTA&=~(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
}

void lcd_char(char chr)
{
	PORTB=chr;
	PORTA|=(1<<rs);
	PORTA&=~(1<<rw);
	PORTA|=(1<<en);
	_delay_ms(1);
	PORTA&=~(1<<en);
}


void lcd_str(char *str)
{

while(*str)	
lcd_char(*str++);
	
}	


void dec_to_ascii(unsigned int dec)
{
	
	//lcd_char( (dec/100)+0x30 );
	lcd_char( ((dec/10)%10)+0x30 );
	lcd_char( ((dec%10)+0x30 ));
	
}



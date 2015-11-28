/*
 * IncFile1.h
 *
 * Created: 9/5/2012 6:42:32 AM
 *  Author: Innovation
 */ 

#define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<inttypes.h>

#define rs PA5
#define rw PA6
#define en PA7

void lcd_init();
void lcd_cmd(char);
void lcd_char(char);
void lcd_str(char *);


void dec_to_ascii(unsigned int dec);
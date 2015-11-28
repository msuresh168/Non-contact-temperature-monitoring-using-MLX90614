/*
 * IR_THERMOGRAPHY.c
 *
 * Created: 20-May-13 5:58:46 AM
 *  Author: Innovation
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#include "MLX90614.h"
#include "UART.h"
#include "LCD.h"


#define DEVICE_ADD    0xB4
#define WRITE         0x00
#define READ          0x01
#define KbpsBAUDRATE  0x2A // 100Kbps

#define RAM_ADD       0x07

double Temp_value,tempFactor;
double kelvin,fahrenheit,celcius;
unsigned int kelvin_disp,celcius_disp;

void Ascii_Conv(unsigned int dis_value);

int main(void)
{
	DDRB=0xFF;
	DDRA=0xFF;
	
	tempFactor=50;
	
	    lcd_init();
		uart_init();
		//MCP3421_Init(KbpsBAUDRATE);
		//MCP3421_Write(DEVICE_ADD|WRITE,RAM_ADD);
		MLX90614_Init(KbpsBAUDRATE);
		MLX90614_Write(DEVICE_ADD|WRITE,RAM_ADD);
		uart_putstr("IR THERMOGRAPHY Testing>>> \r\n");
        lcd_str("   Temperature  ");

_delay_ms(3000);
    while(1)
    {
		Temp_value=MLX90614_Read(DEVICE_ADD|READ);
     	
		kelvin = (Temp_value / tempFactor);
        celcius = kelvin - 273.15;
		// fahrenheit = (celcius*1.8) + 32;
        
		
		celcius_disp=celcius*100;
		kelvin_disp=kelvin*100;

	    uart_putstr("Temperature: ");lcd_cmd(0xC0);
        Ascii_Conv(celcius_disp);uart_putc(248);uart_putc('C'); lcd_char('C');
		uart_putstr(" | ");lcd_str(" | ");
		Ascii_Conv(kelvin_disp);uart_putc(248);uart_putc('K');  lcd_char('K');
		uart_putstr("\r");	
		
		
  
        _delay_ms(2000);
    }
}


void Ascii_Conv(unsigned int dis_value)
{

    uart_putc( (dis_value/10000)+0x30 );
    uart_putc( ((dis_value/1000)%10)+0x30 );
    uart_putc( ((dis_value/100)%10)+0x30 );
    uart_putc('.');
    uart_putc( ((dis_value/10)%10)+0x30 );
    //uart_putc( (dis_value%10)+0x30 );
    
	
	lcd_char( (dis_value/10000)+0x30 );
	lcd_char( ((dis_value/1000)%10)+0x30 );
	lcd_char( ((dis_value/100)%10)+0x30 );
	lcd_char('.');
	lcd_char( ((dis_value/10)%10)+0x30 );
	//lcd_char( (dis_value%10)+0x30 );

	
}	

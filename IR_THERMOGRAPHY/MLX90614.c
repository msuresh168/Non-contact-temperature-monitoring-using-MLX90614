/*
 * MCP3421.c
 *
 * Created: 5/9/2013 8:39:58 PM
 *  Author: Admin
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "MLX90614.h"
#include "i2c.h"


void MLX90614_Init(unsigned char BaudRate)
{
	
	TWBR=BaudRate;	// set Bit rate value
	TWSR=(0<<TWPS1)|(0<<TWPS0);	//set prescalar value	
	
	
}

void MLX90614_Write(unsigned char W_Address,unsigned char Config_value)
{
	i2c_start();_delay_ms(1);
	i2c_write_address(W_Address);_delay_ms(1);
	i2c_write_data(Config_value);_delay_ms(1);
	i2c_stop();_delay_ms(1);
}


double MLX90614_Read(unsigned char R_Address)
{
int dataH,dataL,dataC;	
double Tempdata;
	
	i2c_start();
	i2c_write_address(0xB4);
	i2c_write_data(0x07);
	i2c_repeated_start();
	i2c_read_address(0xB5);
	dataL=i2c_read_data_ACK(1);
	dataH=i2c_read_data_ACK(1);
	dataC=i2c_read_data_NACK(0);
	i2c_stop();_delay_ms(1);
	
	
Tempdata = (((dataH&0x007F)<<8) + dataL);
return(Tempdata);
}






/******************************************************************************************/
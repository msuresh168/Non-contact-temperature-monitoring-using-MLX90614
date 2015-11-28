# define F_CPU 8000000UL
#include<avr/io.h>
#include<util/delay.h>
#include<inttypes.h>
#include"i2c.h"

/*
SCL freq= F_CPU/(16+2(TWBR).4^TWPS)
SCL freq  =8000000/(16+2(1).4^1)
*/

void i2c_init(void)
{
	TWBR=32;	// set Bit rate value
	TWSR=0x00;	//set prescalar value
}

void i2c_start(void)
{
	
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// Clear i2c interrupt flag,set for start condition on SDA, Enable i2c protocol
	while(!(TWCR & (1<<TWINT)));          // Wait till start condition is transmitted
	while((TWSR & 0xF8)!= 0x08);          // start condition acknowledgment
}

void i2c_repeated_start(void)
{
	TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);// Clear i2c interrupt flag,set for start condition on SDA, Enable i2c protocol
	while(!(TWCR & (1<<TWINT)));          // wait till restart condition is transmitted
	while((TWSR & 0xF8)!= 0x10);          // restart condition the acknowledgment
}

void i2c_write_address(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear i2c interrupt flag, Enable i2c protocol
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8)!= 0x18);  // Check for the acknowledgment
}

void i2c_read_address(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear i2c interrupt flag,Enable i2c protocol
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte received
	while((TWSR & 0xF8)!= 0x40);  // Check for the acknowledgment
}

void i2c_write_data(unsigned char data)
{
	TWDR=data;
	TWCR=(1<<TWINT)|(1<<TWEN);    // Clear i2c interrupt flag,Enable i2c protocol enable
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while((TWSR & 0xF8) != 0x28); // Check for the acknowledgment
}

//unsigned char i2c_read_data_ACK(void)
//{
	//TWCR=(1<<TWINT)|(1<<TWEN);    // Clear TWI interrupt flag,Enable TWI
	//while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	//while((TWSR & 0xF8) != 0x50); // Check for the acknowledgment
	//r_data=TWDR;
	//return(r_data);
//}
//
unsigned char i2c_read_data_ACK(unsigned char ack)
{
	
	if(ack)
	{
		//return ACK after reception
		TWCR|=(1<<TWEA);
	}
	else
	{
		//return NACK after reception
		//Signals slave to stop giving more data
		//usually used for last byte read.
		TWCR&=(~(1<<TWEA));
	}

    TWCR|=(1<<TWEN);
	TWCR|=(1<<TWINT);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while( ((TWSR & 0xF8) != 0x50) ) ; // DATA+ACK
	r_data=TWDR;
	return(r_data);
}

unsigned char i2c_read_data_NACK(unsigned char ack)
{
	
	if(ack)
	{
		//return ACK after reception
		TWCR|=(1<<TWEA);
	}
	else
	{
		//return NACK after reception
		//Signals slave to stop giving more data
		//usually used for last byte read.
		TWCR&=(~(1<<TWEA));
	}

	TWCR|=(1<<TWEN);
	TWCR|=(1<<TWINT);    // Clear TWI interrupt flag,Enable TWI
	while (!(TWCR & (1<<TWINT))); // Wait till complete TWDR byte transmitted
	while( ((TWSR & 0xF8) != 0x58) ) ; // DATA+NACK
	r_data=TWDR;
	return(r_data);
}




void i2c_stop(void)
{
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	while(TWCR & (1<<TWSTO));
}
/*
 * MCP3421.h
 *
 * Created: 5/9/2013 9:10:18 PM
 *  Author: Admin
 */ 


#ifndef MLX90614_H_
#define MLX90614_H_

# define F_CPU 8000000UL

void MLX90614_Init(unsigned char BaudRate);
void MLX90614_Write(unsigned char W_Address,unsigned char Config_value);
double MLX90614_Read(unsigned char R_Address);



#endif /* MLX90614_H_ */

#define F_CPU 8000000UL
void i2c_start(void);
void i2c_repeated_start(void);
void i2c_init(void);
void i2c_write_address(unsigned char);
void i2c_write_data(unsigned char);
void i2c_read_address(unsigned char);
unsigned char i2c_read_data_ACK(unsigned char ack);
unsigned char i2c_read_data_NACK(unsigned char ack);

void i2c_stop(void);

unsigned char r_data;
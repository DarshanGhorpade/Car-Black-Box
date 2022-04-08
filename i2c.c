#include <xc.h>
#include "i2c.h"

void init_i2c(unsigned long baud)
{
    /* Set I2C Master Mode */
    SSPM3 = 1;
    
    /* Set the Required Baudrate */
    SSPADD  = (unsigned char)(FOSC / (4 * baud)) - 1;
    
    /* Enable SSP */
    SSPEN = 1;
}

static void i2c_wait_for_idle(void)
{
    /* Wait till no activity on the bus */
    while (R_nW || (SSPCON2 & 0x1F)); // R_nW || (SSPCON2 & 0x1F) == 0
}

void i2c_start(void)
{
    i2c_wait_for_idle();
    SEN = 1;
}

void i2c_rep_start(void)
{
    i2c_stop();
    i2c_start();
    
}

void i2c_stop(void)
{
    i2c_wait_for_idle();
    PEN = 1;
}

unsigned char i2c_read(unsigned char ack)
{
    unsigned char data;
    
    i2c_wait_for_idle();
    RCEN = 1;
    
    i2c_wait_for_idle();
    data = SSPBUF;
    
    if (ack == 1)
    {
        ACKDT = 1;
    }
    else
    {
        ACKDT = 0;
    }
  
    ACKEN = 1;
    
    return data;
}

int i2c_write(unsigned char data)
{
    i2c_wait_for_idle();
    SSPBUF = data;
    
    return !ACKSTAT; // !1
}
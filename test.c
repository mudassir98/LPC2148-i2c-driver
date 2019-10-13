#include"lpc2148_i2c_yapphdr.h"
#include<lpc21xx.h>

#define pclk  12000000
#define master_freq 100000

#define SLAVE_ADDR		0x30

int main()
{ 
	
 
	struct lpc2148_i2c_prv_data p_data;
	struct lpc2148_i2c_device_apis *apis;
	PINSEL0 = PINSEL0 | 0x00000050; 
	//PLLFEED=0X00;
	//PLLCFG=0X00;
	VPBDIV=0X01;
	apis=lpc2148_i2c_device_open();
  lpc2148_i2c_init(&p_data,0x00);
	
	
	
	
		while(1)
		{	
			apis->i2c_config( master_freq,pclk,&p_data);
			apis->i2c_start(&p_data);

			apis->device_write(0x35,SLAVE_ADDR,&p_data);
		
			apis->i2c_stop(&p_data);
		}
}

void SystemInit (void)
{
	
}



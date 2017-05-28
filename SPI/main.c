/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#include "stm8s.h"
void spi_data(unsigned char a);
void spi_init(void);

void main()
{
		GPIOC->DDR=0xff;// c port ouput mosi and sck
       
		GPIOB->ODR=0xff;
				
		spi_init();
	
		spi_data(0x55);
							
		while(1);
							
}
								
void spi_data(unsigned char k)
{ 
	GPIOB->ODR=0x00;// sthp pulse
	SPI->DR=k;			//for txe low										
	while((SPI->SR&=0x02)==0x02); 
	while((SPI->SR&=0x80)==0x80);
	
	GPIOB->ODR=0xff;
}



void spi_init()
{	

	CLK->PCKENR1=0x02;// master freq to spi 
             
	CLK->PCKENR2=0x00;//other peripheral off
													
  SPI->CR1=0x00;		//disable spi
	
  SPI->CR1|=0x38;			//cpol low cpha high
								
	SPI->CR1|=0x0;   // spi enable with lsb first and 	prescaled by 256
					
	SPI->CR1|=0x00;
	
  SPI->CR2=0x03;  
  
  SPI->CR1|=0x44;

}

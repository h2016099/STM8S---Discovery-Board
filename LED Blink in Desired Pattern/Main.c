
#include "stm8s.h"

main()
{
int i=0;
GPIOE->DDR &= 0x7f; 			//Port E as an input
GPIOE->CR1 |= 0x80; 			// Pullup with Interrupt
GPIOB->DDR |= 0x0f; 			//Port B output
GPIOB->CR1 |= 0x0f; 			//push pull o/p

while(1)
{
while(((GPIOE->IDR)&(0x80))!=0x00); 
	{
		while(((GPIOD->IDR)&(0x80))==0x00);
		{
		switch(i)
		{
			case 0:GPIOB->ODR=0x00;			// ALL LED OFF CASE
			case 1:GPIOB->ODR=0x01;			//FIRST LED ON
			case 2:GPIOB->ODR=0x03;			//THEN SECOND
			case 3:GPIOB->ODR=0x07;			// THEN THIRD
			case 4:GPIOB->ODR=0x0f;			// THEN FOURTH
		}
		i++;
		if(i==5)
			{
				i=0;
			}
		}
	}
}
}

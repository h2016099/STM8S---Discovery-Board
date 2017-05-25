/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */


#include "stm8s.h"
void delay();
void led_d(int);
void radc();
void delay(void)
{
int s,j;

for(s=0;s<=250;s++)
{
for(j=0;j<=100;j++);
}
}
void radc(void)
{int data;
{while(1) //((ADC1->CSR)&&(0x80))!=0x00
{
ADC1->CR1=0x43;
delay();
//delay();
ADC1->CR2=0x08;
//delay();
data=(ADC1->DRH);
data=(data<<8);
data|=(ADC1->DRL); //>=10)&&((((ADC1->CSR))&&(0x80))!=0x00)
led_d(data);


}
}
}

void led_d(int p)
{
	if(p==0)
	{
	GPIOB->ODR=0x00;
  }
else if( p>0&&p<=150)//0-1v
{

GPIOB->ODR=0x02;
	delay();
	GPIOB->ODR=0x00;	
	delay();
}

else if(p>150&&p<=225)//1volt
{

GPIOB->ODR=0x02;
}
	else if(p>225&&p<=400)//1-2v
{
 GPIOB->ODR=0x06;
	delay();
	GPIOB->ODR=0x02;	
	delay();
}
else if(p>400&&p<=450)//2v	
{
GPIOB->ODR=0x06;
}
else if(p>450&&p<=600)	//2-3v
{
GPIOB->ODR=0x0e;
	delay();
	GPIOB->ODR=0x06;	
	delay();
}
else if(p>600&&p<=650)//3v
{
GPIOB->ODR=0x0e;
}
else if(p>650&&p<=800)//3-4v
{
GPIOB->ODR=0x1e;
	delay();
	GPIOB->ODR=0x0e;	
	delay();
}
else if(p>800&&p<=840 )//4v
{GPIOB->ODR=0x1e;
}
else if(p>840&&p<=1000)
{GPIOB->ODR=0x3e;
	delay();
	GPIOB->ODR=0x1e;	
	delay();
}
else// if(data>1000)
{
GPIOB->ODR=0x3e;
}
}
void main()
{
			GPIOB->DDR=0x3e;
			GPIOB->CR1=0x3e;
			ADC1->CR1=0x43;
			ADC1->CSR=0x00;
			radc();
}


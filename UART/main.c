/* MAIN.C file
 * 
 * Copyright (c) 2002-2005 STMicroelectronics
 */
#include "stm8s.h"
//#include "stm8s_uart1.h"
void delay(int time);
void delay(int time)
{
int s,j;
for(s=0;s<=time;s++)
{
for(j=0;j<=100;j++);

//for(k=0;k<=10;k++);}

}}

void uart_init(void);

 void txtUART(void);
 //void txUART(char);
main()
{//char s;
GPIOB->DDR=0x00;// use pin 0 & 1 OF PORT B .
GPIOD->DDR=0xff;//tx and rx output uart 2

uart_init();

//GPIOB->ODR=0xff;//random pin value
//s=GPIOB->ODR;

//txUART('I');

while(1)
{
txtUART();
}
}

void uart_init()
{


CLK->ICKR=0x01;//hsi enable
	CLK->CKDIVR=0x00;//master not prescaled
			CLK->CMSR=0xe1;//hsi is the master clock
            CLK->PCKENR1=0xff;// master freq to uart 
								UART2->BRR1=0x68;//9600 baud rate
                     UART2->BRR2=0x03;//9600 baud
                          UART2->CR1=0x00;//word length 8 bit
														UART2->CR2=0x00; //t enable
														     UART2->CR3=0x00;//stop bit 1
		
 
}
/*void txUART(char d)
{

		UART2->DR=d;

	 UART2->CR2=0x08;	

//txtUART();


//		UART2->CR2=0x00;	// transmission disable
		
		
//if ((UART2->SR)&=(0x80)==1)//txe check
//{
//txtUART();
//}

}*/
void txtUART()
{
int i=0;
//txUART('S');

//char *str;
if (GPIOB->IDR==0x00)
{char state[]="LOW LOW \n\r" ;
	while(state[i])
{	
UART2->DR=state[i];
	 UART2->CR2=0x08;//t enable
	 while((((UART2->SR)&&(0x80))==0x00)&(((UART2->SR)&&(0x40))!=0x40)); //check txe =1 & tc =0

//txUART(state[i]);
delay(1);
i++;

}
}
else if (GPIOB->IDR==0x01)
{char state[]=" LOW HIGH \n\r" ;
	while(state[i])
{	
UART2->DR=state[i];
	 UART2->CR2=0x08;
	 while((((UART2->SR)&&(0x80))==0x00)&(((UART2->SR)&&(0x40))!=0x40));

//txUART(state[i]);
delay(1);
i++;

}
}
else if (GPIOB->IDR==0x02)
{char state[]=" HIGH LOW \n\r" ;
	while(state[i])
{	
UART2->DR=state[i];
	 UART2->CR2=0x08;
	 while((((UART2->SR)&&(0x80))==0x00)&(((UART2->SR)&&(0x40))!=0x40));

//txUART(state[i]);
delay(1);
i++;

}
}


else if (GPIOB->IDR==0x03)
{char state[]=" HIGH HIGH \n\r" ;
	while(state[i])
{	
UART2->DR=state[i];
	 UART2->CR2=0x08;
	 while((((UART2->SR)&&(0x80))==0x00)&(((UART2->SR)&&(0x40))!=0x40));

//txUART(state[i]);
delay(1);
i++;

}
}



}

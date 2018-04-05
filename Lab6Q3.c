#include<LPC17xx.h>
unsigned int i, j;
unsigned long LED = 0x00000010;
unsigned int in=0;
unsigned int t = 0;

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR |= 0x00000FF0;
	LED=0x00000010;
while(1)
{
	for(i=0;i<9;i++)
	{
		LPC_GPIO0->FIOSET=LED;
		for(i=0;i<10000;i++);
		
		LPC_GPIO0->FIOCLR=LED;
		LED<<=1;
		if(LED==0x00001000)
			LED=0x00000010;
		
	}
}
}

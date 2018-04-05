#include<LPC17xx.h>
unsigned int i,j;
unsigned long int LED=0x00000010;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0&=0xFF0000FF;
	LPC_GPIO0->FIODIR|=0x00000FF0;
	while(1)
	{
		LED=0x00000010;
		for(i=0;i<255;i++)
		{
			LED=i<<4;
				LPC_GPIO0->FIOPIN=LED;
				i++;
				if(i==255)
					i=0;
				for(j=0;j<255000;j++);

		}
	}
}

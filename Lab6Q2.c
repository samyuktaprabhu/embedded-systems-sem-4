#include<LPC17xx.h>
unsigned int i,j;
unsigned long int LED;
int main(void)
{
	LPC_PINCON->PINSEL0&=0xFF0000FF;
	LPC_GPIO0->FIODIR|=0x00000FF0;
	while(1)
	{
		if(!((LPC_GPIO2->FIOPIN)&(1<<12)))
			{
				LED=i<<4;
				LPC_GPIO0->FIOPIN=LED;
				i++;
				if(i==255)
					i=0;
				for(j=0;j<25500;j++);
			}
			else
			{
				LED=i<<4;
				LPC_GPIO0->FIOPIN=LED;
				i--;
				if(i<0)
					i=255;
				for(j=0;j<25500;j++);
			}
	}
}

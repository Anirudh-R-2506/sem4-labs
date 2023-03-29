 
#include <LPC17xx.h>

int main(void)
{
	unsigned long led;
	unsigned int j;
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON->PINSEL0 &= 0xFF0000FF;
	LPC_GPIO0->FIODIR1 |= 0x00000FF0;
	LPC_PINCON->PINSEL4 &= 0xFCFFFFFF;
	LPC_GPIO2->FIODIR &= 0XFFFFFFFF;

	while (1) {
		
		if (LPC_GPIO2->FIOPIN & 1 << 12){
			for (led = 255; led >= 0; led--){
				LPC_GPIO0->FIOPIN = led << 4;
				for (j = 0; j < 1000; j++);
			}
		}
		else{
			for (led = 0; led <= 255; led++){
				LPC_GPIO0->FIOPIN = led << 4;
				for (j = 0; j < 1000; j++);
			}
		}
	}
	return 0;
}
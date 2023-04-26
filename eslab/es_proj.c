#include <LPC17xx.h>

#define RED (1<<22)
#define YELLOW (1<<21)
#define GREEN (1<<20)
#define PEDRED (1<<19)
#define PEDGREEN (1<<18)
#define PEDBUTTON (1<<17)

void display_delay(){
	unsigned int i;
	for(i=0; i<6000000; i++);
}

void EINT3_IRQHandler(void)// pedestrian crossing
{
    NVIC_DisableIRQ(EINT3_IRQn);
    LPC_GPIO2->FIOPIN &= ~(GREEN | YELLOW);
    LPC_GPIO2->FIOPIN |= PEDRED;
    display_delay();
    LPC_GPIO2->FIOPIN &= ~PEDRED;
    LPC_GPIO2->FIOPIN |= PEDGREEN;
    display_delay();
    LPC_GPIO2->FIOPIN &= ~PEDGREEN;
    LPC_GPIO2->FIOPIN |= YELLOW;
    display_delay();
    LPC_GPIO2->FIOPIN &= ~(YELLOW | PEDGREEN);
    LPC_GPIO2->FIOPIN |= GREEN;

    LPC_GPIOINT->IO2IntClr |= PEDBUTTON;

    NVIC_EnableIRQ(EINT3_IRQn);
}

int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
    LPC_GPIO2->FIODIR |= RED | YELLOW | GREEN | PEDRED | PEDGREEN;
    LPC_GPIO2->FIODIR &= ~PEDBUTTON;
    LPC_GPIO2->FIOPIN |= GREEN;
    LPC_GPIOINT->IO2IntEnF |= PEDBUTTON;
    NVIC_EnableIRQ(EINT3_IRQn);

    while(1)// traffic light changes
    {
        LPC_GPIO2->FIOPIN &= ~(GREEN | YELLOW);
        LPC_GPIO2->FIOPIN |= RED;
        display_delay();
        LPC_GPIO2->FIOPIN &= ~(RED | YELLOW);
        LPC_GPIO2->FIOPIN |= YELLOW;
        display_delay();
        LPC_GPIO2->FIOPIN &= ~(RED | YELLOW);
        LPC_GPIO2->FIOPIN |= GREEN;
        display_delay();
    }
}

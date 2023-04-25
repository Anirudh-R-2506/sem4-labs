#include <LPC17xx.h>

#define RED (1<<22)
#define YELLOW (1<<21)
#define GREEN (1<<20)
#define PEDRED (1<<19)
#define PEDGREEN (1<<18)
#define PEDBUTTON (1<<17)
#define DELAY 6000000

void EINT3_IRQHandler(void)
{
    // disable interrupts to avoid button debouncing
    NVIC_DisableIRQ(EINT3_IRQn);

    // pedestrian crossing
    LPC_GPIO2->FIOPIN &= ~(GREEN | YELLOW);
    LPC_GPIO2->FIOPIN |= PEDRED;
    for(int i=0; i<DELAY; i++);
    LPC_GPIO2->FIOPIN &= ~PEDRED;
    LPC_GPIO2->FIOPIN |= PEDGREEN;
    for(int i=0; i<DELAY; i++);
    LPC_GPIO2->FIOPIN &= ~PEDGREEN;
    LPC_GPIO2->FIOPIN |= YELLOW;
    for(int i=0; i<DELAY; i++);
    LPC_GPIO2->FIOPIN &= ~(YELLOW | PEDGREEN);
    LPC_GPIO2->FIOPIN |= GREEN;

    // clear interrupt flag
    LPC_GPIOINT->IO2IntClr |= PEDBUTTON;

    // enable interrupts again
    NVIC_EnableIRQ(EINT3_IRQn);
}

int main(void)
{
    // set pins as output
    LPC_GPIO2->FIODIR |= RED | YELLOW | GREEN | PEDRED | PEDGREEN;

    // set pin as input
    LPC_GPIO2->FIODIR &= ~PEDBUTTON;

    // set green light as default
    LPC_GPIO2->FIOPIN |= GREEN;

    // set external interrupt on falling edge of pin P2.17 (PEDBUTTON)
    LPC_GPIOINT->IO2IntEnF |= PEDBUTTON;

    // enable interrupt for EINT3_IRQn (external interrupt 3)
    NVIC_EnableIRQ(EINT3_IRQn);

    while(1)
    {
        // automatic light changes
        LPC_GPIO2->FIOPIN &= ~(GREEN | YELLOW);
        LPC_GPIO2->FIOPIN |= RED;
        for(int i=0; i<DELAY; i++);
        LPC_GPIO2->FIOPIN &= ~(RED | YELLOW);
        LPC_GPIO2->FIOPIN |= YELLOW;
        for(int i=0; i<DELAY; i++);
        LPC_GPIO2->FIOPIN &= ~(RED | YELLOW);
        LPC_GPIO2->FIOPIN |= GREEN;
        for(int i=0; i<DELAY; i++);
    }
}

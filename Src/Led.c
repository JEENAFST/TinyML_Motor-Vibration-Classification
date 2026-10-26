
#include "Led.h"
#include "stm32f407.h"

void setgpiopin_state(LED L,int Led_status)//setgpiopin_state(L1,0)
{
	L.state = Led_status;//0
	if((L.state)==1)
	{
		GPIOD->ODR |= (1 << (L.pin));
	}

	else
	{
			GPIOD->ODR &= ~ (1 << (L.pin));
	}
}
void  initialize_gpiocpin(LED L)
{
	    GPIOD->MODER &= ~(3 << ((L.pin)* 2)); //
	    GPIOD->MODER |=  (1 << ((L.pin) * 2)); // set the bit 0 , LED PD12
}



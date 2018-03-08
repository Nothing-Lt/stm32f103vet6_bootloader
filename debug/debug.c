#include "debug.h"
#include "../hardware.h"
#include "../util/util.h"

void init_debug_led()
{
	struct RCC_STRUCT*  rcc  =(struct RCC_STRUCT*) RCC_BASE;
	struct GPIO_STRUCT* gpiob=(struct GPIO_STRUCT*)GPIOB_BASE;
	
	rcc->APB2ENR=0X8;
	gpiob->CRL=0x3;
}

void flash_debug_led()
{
	struct GPIO_STRUCT* gpiob=(struct GPIO_STRUCT*)GPIOB_BASE;
	
	while(TRUE)
	{
		gpiob->ODR=TRUE;
		delay_ms(100000);
		gpiob->ODR=FALSE;
		delay_ms(100000);
	}
}
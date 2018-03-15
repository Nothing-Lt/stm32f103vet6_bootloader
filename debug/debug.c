#include "debug.h"
#include "../hardware.h"
#include "../util/util.h"

void debug_led_init()
{
	struct RCC_STRUCT*  rcc  =(struct RCC_STRUCT*) RCC_BASE;
	struct GPIO_STRUCT* gpiob=(struct GPIO_STRUCT*)GPIOB_BASE;
	
	rcc->APB2ENR=0X8;
	gpiob->CRL=0x3;
}

void debug_led_flash()
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

void debug_usart_init(int buadrate)
{

}

void debug_usart_log(char* debug_str)
{

}
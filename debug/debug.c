#include "debug.h"
#include "../hardware.h"
#include "../util/util.h"

#define USART_TC  (1<<6)

unsigned short AHBAPBPrescTable[]={0,0,0,0,1,2,3,4,1,2,3,4,6,7,8,9};

void debug_led_init()
{
	struct RCC_STRUCT*  rcc  =(struct RCC_STRUCT*) RCC_BASE;
	struct GPIO_STRUCT* gpiob=(struct GPIO_STRUCT*)GPIOB_BASE;
	
	rcc->APB2ENR |= RCC_APB2PERIPH_GPIOB;
	gpiob->CRL   |= 0x3;
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
	struct RCC_STRUCT*  rcc   =(struct RCC_STRUCT*)   RCC_BASE;
	struct GPIO_STRUCT* gpioa =(struct GPIO_STRUCT*)  GPIOA_BASE;
	struct USART_STRUCT* usart=(struct USART_STRUCT*) USART1_BASE;
	int temp=0;
	unsigned short m,f,brr;
	unsigned int div=0;

	rcc->APB2ENR |= RCC_APB2PERIPH_GPIOA;
	rcc->APB2ENR |= RCC_APB2PERIPH_USART1;
	gpioa->CRH   |= 0x4B0;

	temp=1<<3;
	usart->CR1 |= temp;
	temp=(1<<12);//|(1<<10);
	usart->CR1 &= ~temp;
	
	temp=(3)<<12;
	usart->CR2 |= ~temp;

	usart->CR3 &= 0xFCFF;

	div=(72*1000*1000/(buadrate*16));
	m=(unsigned short)div;
	f=(div-m)*16;
	brr=(m<<4)|f;
	usart->BRR = (unsigned short)brr;

	usart->CR1 |= (1<<13);
}

void debug_usart_put_char(char data)
{
	struct USART_STRUCT* usart = (struct USART_STRUCT*)USART1_BASE;
	usart->DR = data;
	while((usart->SR & USART_TC) == FALSE);

}

void debug_usart_log(char* str)
{
	int i=0;
	for(;str[i]!='\0';i++)
	{
		debug_usart_put_char('x');
	}
}
#include "hardware_init.h"
#include "hardware.h"

void system_init()
{
	struct RCC_STRUCT* rcc = (struct RCC_STRUCT*)RCC_BASE;
	struct SCB_STRUCT* scb = (struct SCB_STRUCT*)SCB_BASE;

	rcc->CR |= (uint32_t)0x00000001;   /*reset HSION bit*/

    rcc->CFGR &= (uint32_t)0xF8FF0000; /*reset SW,HPRE,PPRE1,PPRE2,ADCPRE,MCO bits*/

    rcc->CR &= (uint32_t)0xFEF6FFFF;   /*reset HSEON,CSSON,PLLON bits*/

    rcc->CR &= (uint32_t)0xFFFBFFFF;   /*reset HSEBYP bit*/

    rcc->CFGR &= (uint32_t)0xFF80FFFF; /*reset PLLSRC,PLLXTPRE,PLLMUL,USBPRE/OTGFSPRE bits*/

	rcc->CIR = 0x009F0000;             /*disable all interrupts and clear pending bits*/

	rcc->CFGR2 = 0x00000000;           /* Reset CFGR2 register */

 	system_extrame_memory_init();

 	system_clock_init();

 	scb->VTOR |= 0X8000000;
}

void system_extrame_memory_init()
{
	struct RCC_STRUCT* rcc=(struct RCC_STRUCT*)RCC_BASE;
	struct GPIO_STRUCT* gpiod=(struct GPIO_STRUCT*)GPIOD_BASE;
	struct GPIO_STRUCT* gpioe=(struct GPIO_STRUCT*)GPIOE_BASE;
	struct GPIO_STRUCT* gpiof=(struct GPIO_STRUCT*)GPIOF_BASE;
	struct GPIO_STRUCT* gpiog=(struct GPIO_STRUCT*)GPIOG_BASE;
	struct FSMC_BANK1_STRUCT* fsmc=(struct FSMC_BANK1_STRUCT*)FSMC_BANK1_R_BASE;

	rcc->AHBENR  = 0x114;
	rcc->APB2ENR = 0x1E0;

	gpiod->CRL = 0x44BB44BB;
	gpiod->CRH = 0xBBBBBBBB;
	gpioe->CRL = 0xB44444BB;
	gpioe->CRH = 0xBBBBBBBB;
	gpiof->CRL = 0x44BBBBBB;
	gpiof->CRH = 0xBBBB4444;
	gpiog->CRL = 0x44BBBBBB;
	gpiog->CRH = 0x44444B44;

	fsmc->BTCR[4]=0x1011;
	fsmc->BTCR[5]=0x200;

}

void system_clock_init()
{
	struct RCC_STRUCT* rcc=(struct RCC_STRUCT*)RCC_BASE;
	struct FLASH_STRUCT* flash=(struct FLASH_STRUCT*)FLASH_BASE;
	int HSE_status=0,test_count=0;

	rcc->CR |= 0x10000;
	do{
		HSE_status = rcc->CR & 0x20000;
		test_count++;
	}while(HSE_status == 0 && (test_count<500));

	if(rcc->CR & 0x20000)
	{
		HSE_status = 1;
	}
	else
	{
		HSE_status = 0;
	}

	if(HSE_status == 1)
	{
		flash->ACR |= 0x10;
		flash->ACR &= ~0x3;
		flash->ACR |= 0x2;

		rcc->CFGR |= 0x0;
		rcc->CFGR |= 0x0;
		rcc->CFGR |= 0x400;

		rcc->CFGR &= ~(0x10000|0x20000|0x3C0000);
		rcc->CFGR |= 0x10000|0x1C0000;

		rcc->CR |= 0x1000000;
		
		while(!(rcc->CR & 0x2000000));

		rcc->CFGR &= ~(0x3);
		rcc->CFGR |= 0x2;

		while((rcc->CFGR & 0xC)!=0x8);
	}
	else
	{
		/**HSE INITIAL FAILED**/
	}


}

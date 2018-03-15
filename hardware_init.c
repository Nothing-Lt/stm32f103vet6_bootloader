#include "hardware_init.h"
#include "hardware.h"

void system_init()
{
	struct RCC_STRUCT* rcc = (struct RCC_STRUCT*)RCC_BASE;

	rcc->CR |= (uint32_t)0x00000001;   /*reset HSION bit*/

  rcc->CFGR &= (uint32_t)0xF8FF0000; /*reset SW,HPRE,PPRE1,PPRE2,ADCPRE,MCO bits*/

  rcc->CR &= (uint32_t)0xFEF6FFFF;   /*reset HSEON,CSSON,PLLON bits*/

  rcc->CR &= (uint32_t)0xFFFBFFFF;   /*reset HSEBYP bit*/

  rcc->CFGR &= (uint32_t)0xFF80FFFF; /*reset PLLSRC,PLLXTPRE,PLLMUL,USBPRE/OTGFSPRE bits*/

	rcc->CIR = 0x009F0000;             /*disable all interrupts and clear pending bits*/

	rcc->CFGR2 = 0x00000000;           /* Reset CFGR2 register */

 	system_extrame_memory_init();

 	system_clock_init();
}

void system_extrame_memory_init()
{

}

void system_clock_init()
{

}

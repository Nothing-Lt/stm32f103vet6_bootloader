#ifndef HARDWARE_H
#define HARDWARE_H

#define uint32_t unsigned int

#define SCB_BASE     0xE000ED00

#define RCC_BASE     0x40021000
#define USART1_BASE  0x40013800
#define GPIO_BASE    0x40010800
#define GPIOA_BASE   GPIO_BASE
#define GPIOB_BASE  (GPIO_BASE + 0x400)
#define GPIOC_BASE  (GPIO_BASE + 0x800)
#define GPIOD_BASE  (GPIO_BASE + 0xc00)
#define GPIOE_BASE  (GPIO_BASE + 0x1000)
#define GPIOF_BASE  (GPIO_BASE + 0x1800)
#define GPIOG_BASE  (GPIO_BASE + 0x1800)

#define FSMC_BANK1_R_BASE 0xA0000000
#define FLASH_BASE        0x40022000

#define RCC_APB2PERIPH_GPIOA 0x4
#define RCC_APB2PERIPH_GPIOB 0x8
#define RCC_APB2PERIPH_GPIOC 0x10
#define RCC_APB2PERIPH_GPIOD 0x20
#define RCC_APB2PERIPH_GPIOE 0x40
#define RCC_APB2PERIPH_GPIOF 0x80
#define RCC_APB2PERIPH_GPIOG 0x100

#define RCC_APB2PERIPH_USART1 0x4000

struct SCB_STRUCT
{
	uint32_t CPUID;
	uint32_t ICSR;
	uint32_t VTOR;
	uint32_t AIRCR;
	uint32_t SCR;
	uint32_t CCR;
	uint32_t SHP[12];
	uint32_t SHCSR;
	uint32_t CFSR;
	uint32_t HFSR;
	uint32_t DFSR;
	uint32_t MMFAR;
	uint32_t BFAR;
	uint32_t AFSR;
	uint32_t PFR[2];
	uint32_t DFR;
	uint32_t ADR;
	uint32_t MMFR[4];
	uint32_t ISAR[5];
};

struct RCC_STRUCT
{
	uint32_t CR;
	uint32_t CFGR;
	uint32_t CIR;
	uint32_t APB2RSTR;
	uint32_t APB1RSTR;
	uint32_t AHBENR;
	uint32_t APB2ENR;
	uint32_t APB1ENR;
	uint32_t BDCR;
	uint32_t CSR;
	uint32_t CFGR2;
}; 

struct GPIO_STRUCT
{
	uint32_t CRL;
	uint32_t CRH;
	uint32_t IDR;
	uint32_t ODR;
	uint32_t BSRR;
	uint32_t BRR;
	uint32_t LCKR;
};

struct FSMC_BANK1_STRUCT
{
 	uint32_t BTCR[8];
};

struct FLASH_STRUCT
{
	uint32_t ACR;
	uint32_t KEYR;
	uint32_t OPTKEYR;
	uint32_t SR;
	uint32_t CR;
	uint32_t AR;
	uint32_t RESERVED;
	uint32_t OBR;
	uint32_t WRPR;
};

struct USART_STRUCT
{
	uint32_t SR;
	uint32_t DR;
	uint32_t BRR;
	uint32_t CR1;
	uint32_t CR2;
	uint32_t CR3;
	uint32_t GTPR;
};

#endif
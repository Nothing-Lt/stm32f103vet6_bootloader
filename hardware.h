#ifndef HARDWARE_H
#define HARDWARE_H

#define uint32_t unsigned int

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
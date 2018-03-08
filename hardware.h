#ifndef HARDWARE_H
#define HARDWARE_H

#define uint32_t unsigned int

#define RCC_BASE   0x40021000
#define GPIOB_BASE 0x40010c00

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

#endif
#define TRUE        1
#define FALSE       0

#define RCC_BASE    0x40021000
#define RCC_APB2ENR 0x40021018//RCC_BASE + 0x18
#define GPIOB_BASE  0x40010c00
#define GPIOB_ODR   0x40010c0c//GPIOB_BASE + 0xc

#define SET_APB2_GPIOB 0x8
#define SET_GPIOB0_OUT 0x3

void delay_ms(int loop_time)
{
	while(loop_time>=0){loop_time--;}
}

int main()
{
	unsigned int* rcc_apb2enr=(unsigned int*)RCC_APB2ENR;
	unsigned int* gpiob_base =(unsigned int*)GPIOB_BASE;
	unsigned int* gpiob0_odr =(unsigned int*)GPIOB_ODR;

	*rcc_apb2enr= SET_APB2_GPIOB;
	*gpiob_base = SET_GPIOB0_OUT;

	while(TRUE)
	{
		*gpiob0_odr=TRUE;
		delay_ms(1000000);
		*gpiob0_odr=FALSE;
		delay_ms(1000000);
	}

	return 0;
}
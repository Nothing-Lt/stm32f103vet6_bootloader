
.syntax unified
.cpu cortex-m3
.thumb

.global isr_vector
.global Default_Handler 

.word isdata
.word iedata
.word sdata
.word sbss
.word ebss
.word stack_pointer 

.equ BootRAM,0xF1E0F85F

.section  .text.Reset_Handler
.weak  Reset_Handler
.type  Reset_Handler, %function

Reset_Handler:
bl init_data
bl init_bss
bl main

init_data:
movs r0,#0
ldr r1,=isdata
ldr r2,=iedata
ldr r3,=sdata
loop1:
ldr r4,[r1,r0]
str r4,[r3,r0]
add r4,r1,r0
add r0,r0,#4
cmp r4,r2
bcc loop1
mov pc,lr

init_bss:
movs r0,#0
ldr r1,=sbss
ldr r2,=ebss
movs r3,#0
loop2:
str r3,[r1,r0]
add r4,r1,r0
add r0,r0,#4
cmp r4,r2
bcc loop2
mov pc,lr

enter_main:
bl main
mov pc,lr 

Default_Handler:
b Default_Handler

.section vector_table,"a",%progbits
.type isr_vectors,%object
.size isr_vectors, .-isr_vectors

isr_vectors:
.word stack_pointer
.word Reset_Handler
.word NMI_Handler
.word HardFault_Handler
.word MemManage_Handler
.word BusFault_Handler
.word UsageFault_Handler
.word 0
.word 0
.word 0
.word 0
.word SVC_Handler
.word DebugMon_Handler
.word 0
.word PendSV_Handler
.word SysTick_Handler
.word WWDG_IRQHandler
.word PVD_IRQHandler
.word TAMPER_IRQHandler
.word RTC_IRQHandler
.word FLASH_IRQHandler
.word RCC_IRQHandler
.word EXTI0_IRQHandler
.word EXTI1_IRQHandler
.word EXTI2_IRQHandler
.word EXTI3_IRQHandler
.word EXTI4_IRQHandler
.word DMA1_Channel1_IRQHandler
.word DMA1_Channel2_IRQHandler
.word DMA1_Channel3_IRQHandler
.word DMA1_Channel4_IRQHandler
.word DMA1_Channel5_IRQHandler
.word DMA1_Channel6_IRQHandler
.word DMA1_Channel7_IRQHandler
.word ADC1_2_IRQHandler
.word USB_HP_CAN1_TX_IRQHandler
.word USB_LP_CAN1_TR0_IRQHandler
.word CAN1_RX1_IRQHandler
.word CAN1_SCE_IRQhandler
.word EXTI9_5_IRQHandler 
.word TIM1_BRK_IRQHandler
.word TIM1_UP_IRQHandler
.word TIM1_TRG_COM_IRQHandler
.word TIM1_CC_IRQHandler
.word TIM2_IRQHandler
.word TIM3_IRQHandler
.word TIM4_IRQHandler
.word I2C1_EV_IRQHandler
.word I2C1_ER_IRQHandler
.word I2C2_EV_IRQHandler
.word I2C2_ER_IRQHandler
.word SPI1_IRQHandler
.word SPI2_IRQHandler
.word USART1_IRQHandler
.word USART2_IRQHandler
.word USART3_IRQHandler
.word EXTI15_10_IRQHandler
.word RTCAlarm_IRQHandler
.word USBWakeUp_IRQHandler
.word TIM8_BRK_IRQHandler
.word TIM8_UP_IRQHandler
.word TIM8_TRG_COM_IRQHandler
.word TIM8_CC_IRQHandler
.word ADC3_IRQHandler
.word FSMC_IRQhandler
.word SDIO_IRQhandler
.word TIM5_IRQHandler
.word SPI3_IRQHandler
.word UART4_IRQHandler
.word UART5_IRQHandler
.word TIM6_IRQHandler
.word TIM7_IRQHandler
.word DMA2_Channel1_IRQHandler
.word DMA2_Channel2_IRQHandler
.word DMA2_Channel3_IRQHandler
.word DMA2_Channel4_5_IRQHandler
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word 0
.word BootRAM

.weak NMI_Handler
.thumb_set NMI_Handler,Default_Handler


.weak HardFault_Handler
.thumb_set HardFault_Handler,Default_Handler

.weak MemManage_Handler
.thumb_set MemManage_Handler,Default_Handler

.weak BusFault_Handler
.thumb_set BusFault_Handler,Default_Handler

.weak UsageFault_Handler
.thumb_set UsageFault_Handler,Default_Handler

.weak SVC_Handler
.thumb_set SVC_Handler,Default_Handler

.weak DebugMon_Handler
.thumb_set DebugMon_Handler,Default_Handler

.weak PendSV_Handler
.thumb_set PendSV_Handler,Default_Handler

.weak SysTick_Handler
.thumb_set SysTick_Handler,Default_Handler

.weak WWDG_IRQHandler
.thumb_set WWDG_IRQHandler,Default_Handler

.weak PVD_IRQHandler
.thumb_set PVD_IRQHandler,Default_Handler

.weak TAMPER_IRQHandler
.thumb_set TAMPER_IRQHandler,Default_Handler

.weak RTC_IRQHandler
.thumb_set RTC_IRQHandler,Default_Handler

.weak FLASH_IRQHandler
.thumb_set FLASH_IRQHandler,Default_Handler

.weak RCC_IRQHandler
.thumb_set RCC_IRQHandler,Default_Handler

.weak EXTI0_IRQHandler
.thumb_set EXTI0_IRQHandler,Default_Handler

.weak EXTI1_IRQHandler
.thumb_set EXTI1_IRQHandler,Default_Handler

.weak EXTI2_IRQHandler
.thumb_set EXTI2_IRQHandler,Default_Handler

.weak EXTI3_IRQHandler
.thumb_set EXTI3_IRQHandler,Default_Handler

.weak EXTI4_IRQHandler
.thumb_set EXTI4_IRQHandler,Default_Handler

.weak DMA1_Channel1_IRQHandler
.thumb_set DMA1_Channel1_IRQHandler,Default_Handler

.weak DMA1_Channel2_IRQHandler
.thumb_set DMA1_Channel2_IRQHandler,Default_Handler

.weak DMA1_Channel3_IRQHandler
.thumb_set DMA1_Channel3_IRQHandler,Default_Handler

.weak DMA1_Channel4_IRQHandler
.thumb_set DMA1_Channel4_IRQHandler,Default_Handler

.weak DMA1_Channel5_IRQHandler
.thumb_set DMA1_Channel5_IRQHandler,Default_Handler

.weak DMA1_Channel6_IRQHandler
.thumb_set DMA1_Channel6_IRQHandler,Default_Handler

.weak DMA1_Channel7_IRQHandler
.thumb_set DMA1_Channel7_IRQHandler,Default_Handler

.weak ADC1_2_IRQHandler
.thumb_set ADC1_2_IRQHandler,Default_Handler

.weak USB_HP_CAN1_TX_IRQHandler
.thumb_set USB_HP_CAN1_TX_IRQHandler,Default_Handler

.weak USB_LP_CAN1_TR0_IRQHandler
.thumb_set USB_LP_CAN1_TR0_IRQHandler,Default_Handler

.weak CAN1_RX1_IRQHandler
.thumb_set CAN1_RX1_IRQHandler,Default_Handler

.weak CAN1_SCE_IRQhandler
.thumb_set CAN1_SCE_IRQhandler,Default_Handler

.weak EXTI9_5_IRQHandler
.thumb_set EXTI9_5_IRQHandler,Default_Handler

.weak TIM1_BRK_IRQHandler
.thumb_set TIM1_BRK_IRQHandler,Default_Handler

.weak TIM1_UP_IRQHandler
.thumb_set TIM1_UP_IRQHandler,Default_Handler

.weak TIM1_TRG_COM_IRQHandler
.thumb_set TIM1_TRG_COM_IRQHandler,Default_Handler

.weak TIM1_CC_IRQHandler
.thumb_set TIM1_CC_IRQHandler,Default_Handler

.weak TIM2_IRQHandler
.thumb_set TIM2_IRQHandler,Default_Handler

.weak TIM3_IRQHandler
.thumb_set TIM3_IRQHandler,Default_Handler

.weak TIM4_IRQHandler
.thumb_set TIM4_IRQHandler,Default_Handler

.weak I2C1_EV_IRQHandler
.thumb_set I2C1_EV_IRQHandler,Default_Handler

.weak I2C1_ER_IRQHandler
.thumb_set I2C1_ER_IRQHandler,Default_Handler

.weak I2C2_EV_IRQHandler
.thumb_set I2C2_EV_IRQHandler,Default_Handler

.weak I2C2_ER_IRQHandler
.thumb_set I2C2_ER_IRQHandler,Default_Handler

.weak SPI1_IRQHandler
.thumb_set SPI1_IRQHandler,Default_Handler

.weak SPI2_IRQHandler
.thumb_set SPI2_IRQHandler,Default_Handler

.weak USART1_IRQHandler
.thumb_set USART1_IRQHandler,Default_Handler

.weak USART2_IRQHandler
.thumb_set USART2_IRQHandler,Default_Handler

.weak USART3_IRQHandler
.thumb_set USART3_IRQHandler,Default_Handler

.weak EXTI15_10_IRQHandler
.thumb_set EXTI15_10_IRQHandler,Default_Handler

.weak RTCAlarm_IRQHandler
.thumb_set RTCAlarm_IRQHandler,Default_Handler

.weak USBWakeUp_IRQHandler
.thumb_set USBWakeUp_IRQHandler,Default_Handler

.weak TIM8_BRK_IRQHandler
.thumb_set TIM8_BRK_IRQHandler,Default_Handler

.weak TIM8_UP_IRQHandler
.thumb_set TIM8_UP_IRQHandler,Default_Handler

.weak TIM8_TRG_COM_IRQHandler
.thumb_set TIM8_TRG_COM_IRQHandler,Default_Handler

.weak TIM8_CC_IRQHandler
.thumb_set TIM8_CC_IRQHandler,Default_Handler

.weak ADC3_IRQHandler
.thumb_set ADC3_IRQHandler,Default_Handler

.weak FSMC_IRQhandler
.thumb_set FSMC_IRQhandler,Default_Handler

.weak SDIO_IRQhandler
.thumb_set SDIO_IRQhandler,Default_Handler

.weak TIM5_IRQHandler
.thumb_set TIM5_IRQHandler,Default_Handler

.weak SPI3_IRQHandler
.thumb_set SPI3_IRQHandler,Default_Handler

.weak UART4_IRQHandler
.thumb_set UART4_IRQHandler,Default_Handler

.weak UART5_IRQHandler
.thumb_set UART5_IRQHandler,Default_Handler

.weak TIM6_IRQHandler
.thumb_set TIM6_IRQHandler,Default_Handler

.weak TIM7_IRQHandler
.thumb_set TIM7_IRQHandler,Default_Handler

.weak DMA2_Channel1_IRQHandler
.thumb_set DMA2_Chnnale1_IRQHandler,Default_Handler

.weak DMA2_Channel2_IRQHandler
.thumb_set DMA2_Chnnale2_IRQHandler,Default_Handler

.weak DMA2_Channel3_IRQHandler
.thumb_set DMA2_Chnnale3_IRQHandler,Default_Handler

.weak DMA2_Channel4_5_IRQHandler
.thumb_set DMA2_Chnnale4_IRQHandler,Default_Handler

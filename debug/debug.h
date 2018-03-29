#ifndef DEBUG_H
#define DEBUG_H

void debug_led_init();

void debug_led_flash();

void debug_usart_init(int buadrate);

void debug_usart_log(char* str);


#endif
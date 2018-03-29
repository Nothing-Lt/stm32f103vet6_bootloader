#include "hardware_init.h"
#include "debug/debug.h"

int main()
{
	debug_led_init();

	debug_usart_init(115200);

	debug_usart_log("ok");

	debug_led_flash();

	return 0;
}
#include "hardware_init.h"
#include "debug/debug.h"

int main()
{
	debug_led_init();

	debug_led_flash();

	return 0;
}
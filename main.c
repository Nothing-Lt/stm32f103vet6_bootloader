#include "hardware_init.h"
#include "debug/debug.h"

int main()
{
	init_debug_led();

	flash_debug_led();

	return 0;
}
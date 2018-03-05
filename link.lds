
MEMORY
{
	ram (rwx) : ORIGIN = 0x20000000 , LENGTH = 0x00010000
	rom (rx)  : ORIGIN = 0x08000000 , LENGTH = 0x00080000
}

stack_pointer = 0x20000000 + 0x00010000;

SECTIONS
{
	.text :
	{
		KEEP(*(vector_table))
		*(.text*)

		. = ALIGN(4);
		isdata = .;
		*(.data)
		iedata = .;
	
	} > rom

	.data :
	{
		. = ALIGN(4);
		sdata = .;
		*(.data)
	} > ram

	.bss :
	{
		sbss = .;
		*(.bss)
		ebss = .;
	} > ram
}
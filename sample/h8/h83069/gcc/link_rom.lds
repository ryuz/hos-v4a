OUTPUT_ARCH(h8300h)
ENTRY("__reset_handler")

MEMORY
{
	vector : o = 0x000000, l = 0x0100
	rom    : o = 0x000100, l = 0x7f00
	ram    : o = 0xffbf20, l = 0x4000
}

SECTIONS
{
	.vector :
	{
		___vector = . ; 
		*/vector.o(.text)
		FILL(0xff)
		___vector_end = . ; 
	} > vector
	.text :
	{
		 ___text = . ; 
		*(.text)
		*(.strings)
		*(.rodata*)
		 ___text_end = . ; 
	}  > rom
	.tors :
	{
		. = ALIGN(2);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > rom
	data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
	    ___data_rom = ADDR(.tors) + SIZEOF(.tors);
		___data = . ;
		*(.data)
		___data_end = . ;
	} > ram
	.bss :
	{
		___bss = . ;
		*(.bss)
		*(COMMON)
		___bss_end = . ; 
	}  >ram
}


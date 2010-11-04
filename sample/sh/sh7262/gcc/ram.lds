OUTPUT_ARCH(sh)
ENTRY(_reset_handler)

MEMORY
{
	vector : o = 0x1c000000, l = 0x000800
	ro     : o = 0x1c000800, l = 0x027800
	rw     : o = 0x1c028000, l = 0x0d8000
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
	}  > ro
	.tors :
	{
		. = ALIGN(4);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > ro
	data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
	    ___data_rom = ADDR(.tors) + SIZEOF(.tors);
		___data = . ;
		*(.data)
		___data_end = . ;
	} > rw
	.bss :
	{
		___bss = . ;
		*(.bss)
		*(COMMON)
		___bss_end = . ;  
	}  >rw
}


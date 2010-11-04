OUTPUT_ARCH(sh)
ENTRY(_reset_handler)

MEMORY
{
	vector : o = 0x00000000, l = 0x00400
	ro     : o = 0x00000400, l = 0x07c00
	rw     : o = 0xffffe000, l = 0x02000
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
	} > rw
}



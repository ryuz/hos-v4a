OUTPUT_ARCH(arm)
ENTRY(_kernel_reset_handler)

MEMORY
{
	vector : o = 0x00000000, l = 0x000000c0
	ro     : o = 0x000000c0, l = 0x00007f40
	rw     : o = 0x10000000, l = 0x00002000
}

SECTIONS
{
	.vector :
	{
		___vector = . ; 
		*/kernel_vct.o(.data)
		*/kernel_vct.o(.rodata*)
		FILL(0xff)
		___vector_end = . ; 
	} > vector
	.text :
	{
		 ___text = . ; 
		*(.text)
		*(.strings)
		*(.rodata*)
		*(.glue*)
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


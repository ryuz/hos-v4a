OUTPUT_ARCH(mips)
ENTRY(_reset_handler)

MEMORY
{
	ro  : o = 0x00000000, l = 0x00010000
	rw  : o = 0x00010000, l = 0x00001000
}

SECTIONS
{
	.text :
	{
		 ___text = . ; 
		*/crt0.o(.text)
		*(.text)
		*(.strings)
		*(.rodata*)
		*(.glue*)
		 ___text_end = . ; 
	} > ro
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
	.data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
	    ___data_rom = ADDR(.tors) + SIZEOF(.tors);
		___data = . ;
		*(.data)
		_gp = ALIGN(16) + 0x7ff0;
		*(.sdata)
		___data_end = . ;
	} > rw
	.bss :
	{
		___bss = . ;
		*(.sbss)
		*(.bss)
		*(COMMON)
		*(.scommon)
		___bss_end = . ;  
	} > rw
}


OUTPUT_ARCH(arm)
ENTRY(_reset_handler)

MEMORY
{
	vector  : o = 0x80000000, l = 0x00000040
	ro_area : o = 0x80000040, l = 0x0001ffc0
	rw_area : o = 0x80020000, l = 0x000e0000
}

SECTIONS
{
	.vector :
	{
		___vector = . ; 
		*/vectors.o(.text)
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
	}  > ro_area
	.tors :
	{
		. = ALIGN(4);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > ro_area
	data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
	    ___data_rom = ADDR(.tors) + SIZEOF(.tors);
		___data = . ;
		*(.data)
		___data_end = . ;
	} > rw_area
	.bss :
	{
		___bss = . ;
		*(.bss)
		*(COMMON)
		___bss_end = . ;  
	}  > rw_area
}


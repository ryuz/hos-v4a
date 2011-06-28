ENTRY(_reset_handler)

MEMORY
{
	ro     : o = 0x00000100, l = 0x00003f00
	rw     : o = 0x00004000, l = 0x00004000
}

SECTIONS
{
	.vectors.reset 0x00000000 :
	{
		*(.vectors.reset)
	}
	.vectors.sw_exception 0x00000008 :
	{
		*(.vectors.sw_exception)
	}
	.vectors.interrupt 0x00000010 :
	{
		*(.vectors.interrupt)
	}
	.vectors.hw_exception 0x00000020 :
	{
		*(.vectors.hw_exception)
	}
	
	.text :
	{
		 ___text = . ; 
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
	data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
	    ___data_ro = ADDR(.tors) + SIZEOF(.tors);
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


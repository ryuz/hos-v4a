ENTRY(_boot_handler)


SECTIONS
{
	.text :
	{
		 ___text = . ; 
		objs_*/crt0.o(.text)
		*(.text)
		*(.strings)
		*(.rodata*)
		 ___text_end = . ; 
	}
	.tors :
	{
		. = ALIGN(4);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	}
	data : 
	{
		___data = . ;
		*(.data)
		___data_end = . ;
	}
	.bss :
	{
		___bss = . ;
		*(.bss)
		*(COMMON)
		___bss_end = . ;  
	}
}



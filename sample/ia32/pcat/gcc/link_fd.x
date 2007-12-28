ENTRY(ipl_top)

MEMORY
{
	ipl   : o = 0x07c00, l = 0x000400
	load  : o = 0x09000, l = 0x167800
}

SECTIONS
{
	.ipl : AT 0x00000
	{
		___vector = . ; 
		*/bootloader.o(.text)
		FILL(0x00)
		___vector_end = . ; 
	} > ipl
	.text : AT 0x00800
	{
		 ___text = . ; 
		*(.text)
		*(.strings)
		*(.rodata*)
		 ___text_end = . ; 
	}  > load
	.tors :
	{
		. = ALIGN(4);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > load
	data : 
	{
		___data = . ;
		*(.data)
		___data_end = . ;
	} > load
	.bss :
	{
		___bss = . ;
		*(.bss)
		*(COMMON)
		___bss_end = . ;  
	}  >load
}



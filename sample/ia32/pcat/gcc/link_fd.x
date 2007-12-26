ENTRY(ipl_top)

MEMORY
{
/*	ipl   : o = 0x0000000, l = 0x000400
	load  : o = 0x0000400, l = 0x167c00 */

	ipl   : o = 0x0000000, l = 0x168000
	load  : o = 0x0168000, l = 0x167c00
}

SECTIONS
{
	.ipl :
	{
		___vector = . ; 
		*/bootloader.o(.text)
		FILL(0x00)
		___vector_end = . ; 
	} > ipl
	.text :
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
	data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
	    ___data_rom = ADDR(.tors) + SIZEOF(.tors);
		___data = . ;
		*(.data)
		___data_end = . ;
	} > load
	.bss :
	{
		___bss = . ;
		*(.bss)
		*(COMMON)
		FILL(0xff)
		___bss_end = . ;  
	}  >load
}



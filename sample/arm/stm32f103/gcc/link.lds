OUTPUT_ARCH(arm)
ENTRY(_kernel_reset_handler)

MEMORY
{
	vector : o = 0x00000000, l = 0x00001000
	rom    : o = 0x00001000, l = 0x000ff000
	ram    : o = 0x40000000, l = 0x00004000
}

SECTIONS
{
	.vector :
	{
		___vector = . ; 
		*/kernel_vct.o(.text)
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
	}  > rom
	.tors :
	{
		. = ALIGN(4);
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


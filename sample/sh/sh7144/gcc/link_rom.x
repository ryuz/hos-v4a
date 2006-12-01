OUTPUT_FORMAT("elf32-sh")
OUTPUT_ARCH(sh)

MEMORY
{
	vector(r) : o = 0x00000000, l = 0x0400
	rom(rx)   : o = 0x00000400, l = 0x7c00
	ram(rwx)  : o = 0x00400000, l = 0x2000
}

SECTIONS
{
	.vector :
	{
		___vector = . ; 
		*(.vector)
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
	} > rom
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
	} > ram
}


OUTPUT_FORMAT("elf32-h8300")
OUTPUT_ARCH(h8300h)
ENTRY("__reset_handler")
MEMORY
{
	vectors(r) : o = 0x000000, l = 0x0100
	rom(rx)    : o = 0x000100, l = 0x7f00
	ram(rwx)   : o = 0xffbf20, l = 0x4000
}

SECTIONS
{
	.vectors :
	{
		___vectors = . ; 
		*(.vectors)
		FILL(0xff)
		___vectors_end = . ; 
	} > vectors
	.text :
	{
		 ___text = . ; 
		*(.text)
		*(.strings)
		*(.rodata*)
		 ___text_end = . ; 
	} > rom
	.tors : {
		. = ALIGN(4);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > rom
	data :
	{
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


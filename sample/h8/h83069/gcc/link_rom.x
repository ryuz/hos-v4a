OUTPUT_ARCH(h8300h)
ENTRY("__reset_handler")
MEMORY
{
	vector(r) : o = 0x000000, l = 0x0100
	rom(rx)   : o = 0x000100, l = 0x2000
	ram(rwx)  : o = 0xffe140, l = 0x1800
}

SECTIONS
{
	.text :
	{
		 ___text = . ; 
		*(.text)
		*(.strings)
		*(.rodata)
		 ___text_end = . ; 
	}  > rom
	.tors : {
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > rom
	data : AT (ADDR(.tors) + SIZEOF(.tors))
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
	}  >ram
}


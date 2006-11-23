OUTPUT_ARCH(h8300h)
ENTRY("__reset_handler")
MEMORY
{
	vectors : o = 0xffc040, l = 0x0100
	rom     : o = 0xffc140, l = 0x2000
	ram     : o = 0xffe140, l = 0x1800
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


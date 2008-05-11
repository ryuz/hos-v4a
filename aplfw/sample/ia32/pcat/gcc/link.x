ENTRY(_boot_handler)


MEMORY
{
	ram    : o = 0x00008000, l = 0x98000
}


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
	} > ram
	.tors :
	{
		. = ALIGN(4);
		___ctors = . ;
		*(.ctors)
		___ctors_end = . ;
		___dtors = . ;
		*(.dtors)
		___dtors_end = . ;
	} > ram
	.rdata :
	{
		___rdata = . ;
		*(.rdata)
		___rdata_end = . ;
	} > ram
	.eh_frame :
	{
		*(.eh_frame)
	} > ram
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



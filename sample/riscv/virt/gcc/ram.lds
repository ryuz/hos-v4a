OUTPUT_ARCH( "riscv" )
ENTRY(_entry)

MEMORY
{
  ram : ORIGIN = 0x80000000, LENGTH = 32M
}

SECTIONS
{
	.text :
	{
		 ___text = . ;
		*/crt0.o(.text)
		*(.text .text.*)
		*(.rodata*)
		*(.strings)
		*(.glue*)
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
	.data : AT (ADDR(.tors) + SIZEOF(.tors))
	{
		___data = . ;
		*(.data)
		_gp = ALIGN(16) + 0x7ff0;
		*(.sdata)
		___data_end = . ;
	} > ram
	.bss :
	{
		___bss = . ;
		*(.sbss)
		*(.bss)
		*(COMMON)
		*(.scommon)
		___bss_end = . ;
	} > ram
}

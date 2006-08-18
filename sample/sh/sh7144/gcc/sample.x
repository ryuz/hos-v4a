OUTPUT_FORMAT("coff-sh")
OUTPUT_ARCH(sh)
MEMORY
{
  vector : o = 0x00400000, l = 0x00000400
  rom    : o = 0x00400400, l = 0x00010000
  ram    : o = 0x00420000, l = 0x00010000
  stack  : o = 0x0043fff0, l = 0x00000010
}
SECTIONS
{
  .vector :
  {
    _VECTOR_START = . ;
    *(.vector)
  } > vector
  
  .text :
  {
    _TEXT_START = . ;
    *(.vector)
    *(.text)
    *(.strings)
    *(.rodata)
	*(.rodata.str1.4)
    _TEXT_END = . ;
  } > rom
  .data : AT (ADDR(.text) + SIZEOF(.text))
  {
    _DATA_ROM = ADDR(.text) + SIZEOF(.text) ;
    _DATA_START = . ;
    *(.data)
    _DATA_END = . ;
  } > ram
  .bss :
  {
    _BSS_START = . ;
    *(.bss)
    *(COMMON)
    _BSS_END = . ;
  } > ram
  .stack :
  {
    _STACK_START = . ;
    *(.stack);
    _STACK_END = . ;
  } > stack
}

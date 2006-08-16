OUTPUT_FORMAT("coff-sh")
OUTPUT_ARCH(sh)
MEMORY
{
  vector : o = 0xfffff200, l = 0x00000300
  rom    : o = 0x00c00000, l = 0x00020000
  ram    : o = 0x00c20000, l = 0x0001fff0
  stack  : o = 0x00c3fff0, l = 0x00000010
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

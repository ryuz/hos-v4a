/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kini_prc.c
 * @brief %jp{プロセッサ固有の初期化}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "core/core.h"


#define _KERNEL_DT_TYPE_INT		0xe
#define _KERNEL_DT_TYPE_TRAP	0xf


#define _KERNEL_SEG_CODE		0x0008
#define _KERNEL_SEG_DATA		0x0010


UH	_kernel_idtptr[3];
UW  _kernel_idt[256*2];


void _kernel_set_idt(INT vector, UB type, UH seg, UW offset)
{
	_kernel_idt[vector*2+0] = ((((UW)offset) & 0xffff) | (seg << 16));
	_kernel_idt[vector*2+1] = ((type << 8) | 0x00008000 | ((UW)offset & 0xffff0000));
}



/** %jp{プロセッサ固有の初期化} */
void _kernel_ini_prc(void)
{
	_kernel_set_idt(  0, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_000);
	_kernel_set_idt(  1, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_001);
	_kernel_set_idt(  2, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_002);
	_kernel_set_idt(  3, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_003);
	_kernel_set_idt(  4, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_004);
	_kernel_set_idt(  5, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_005);
	_kernel_set_idt(  6, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_006);
	_kernel_set_idt(  7, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_007);
	_kernel_set_idt(  8, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_008);
	_kernel_set_idt(  9, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_009);
	_kernel_set_idt( 10, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_010);
	_kernel_set_idt( 11, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_011);
	_kernel_set_idt( 12, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_012);
	_kernel_set_idt( 13, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_013);
	_kernel_set_idt( 14, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_014);
	_kernel_set_idt( 15, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_015);
	_kernel_set_idt( 16, _KERNEL_DT_TYPE_TRAP, _KERNEL_SEG_CODE, (UW)_kernel_vector_016);
	
	_kernel_set_idt( 32, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_032);
	_kernel_set_idt( 33, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_033);
	_kernel_set_idt( 34, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_034);
	_kernel_set_idt( 35, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_035);
	_kernel_set_idt( 36, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_036);
	_kernel_set_idt( 37, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_037);
	_kernel_set_idt( 38, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_038);
	_kernel_set_idt( 39, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_039);
	_kernel_set_idt( 40, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_040);
	_kernel_set_idt( 41, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_041);
	_kernel_set_idt( 42, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_042);
	_kernel_set_idt( 43, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_043);
	_kernel_set_idt( 44, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_044);
	_kernel_set_idt( 45, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_045);
	_kernel_set_idt( 46, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_046);
	_kernel_set_idt( 47, _KERNEL_DT_TYPE_INT, _KERNEL_SEG_CODE, (UW)_kernel_vector_047);
	
	
	_kernel_idtptr[0] = sizeof(_kernel_idt) - 1;
	_kernel_idtptr[1] = (((UW)_kernel_idt) & 0xffff);
	_kernel_idtptr[2] = (((UW)_kernel_idt >> 16) & 0xffff);
	_kernel_lidt(_kernel_idtptr);
}



/* end of file */

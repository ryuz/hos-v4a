/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ini_irc.c
 * @brief %jp{PC/AT互換機}%en{PC/AT}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"



/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	/* PIC1 初期化 */
	_kernel_outpb(_KERNEL_IRC_PIC1_ICW1, 0x11);
	_kernel_outpb(_KERNEL_IRC_PIC1_ICW2, _KERNEL_IRC_PIC1_VECT);
	_kernel_outpb(_KERNEL_IRC_PIC1_ICW3, 0x04);
	_kernel_outpb(_KERNEL_IRC_PIC1_ICW4, 0x01);
	_kernel_outpb(_KERNEL_IRC_PIC1_OCW3, 0x4a);
	
	/* PIC2 初期化 */
	_kernel_outpb(_KERNEL_IRC_PIC2_ICW1, 0x11);
	_kernel_outpb(_KERNEL_IRC_PIC2_ICW2, _KERNEL_IRC_PIC2_VECT);
	_kernel_outpb(_KERNEL_IRC_PIC2_ICW3, 0x02);
	_kernel_outpb(_KERNEL_IRC_PIC2_ICW4, 0x01);
	_kernel_outpb(_KERNEL_IRC_PIC2_OCW3, 0x4a);
	
	/* 割込み全マスク */
	_kernel_outpb(_KERNEL_IRC_PIC2_OCW1, 0xff);
	_kernel_outpb(_KERNEL_IRC_PIC1_OCW1, 0xfb);
}



/* end of file */

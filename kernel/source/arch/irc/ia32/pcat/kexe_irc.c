/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief %jp{PC/AT互換機}%en{PC/AT}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの割込み処理} */
void _kernel_exe_irc(INHNO inhno)
{
	INTNO intno;
	
	intno = (inhno - _KERNEL_IRC_PIC1_VECT);
	
	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr(intno);
	
	/* EOI */
	if ( intno < 8 )
	{
		_kernel_outpb(_KERNEL_IRC_PIC1_OCW2, (intno | 0x60));
	}
	else
	{
		_kernel_outpb(_KERNEL_IRC_PIC2_OCW2, ((intno - 8) | 0x60));
		_kernel_outpb(_KERNEL_IRC_PIC1_OCW2, 0x62);
	}
}


/* end of file */

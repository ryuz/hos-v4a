/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief %jp{Freescale MX1用}%en{Freescale MX1}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの割込み処理} */
void _kernel_exe_irc(INHNO inhno)
{
	INTNO intno;

	switch ( inhno )
	{
	case _KERNEL_ARM_INHNO_IRQ:
		intno = (*_KERNEL_IRC_NIVECSR >> 16);
		break;

	case _KERNEL_ARM_INHNO_FIQ:
		intno = *_KERNEL_IRC_NIVECSR;
		break;
	
	default:
		return;
	}

	/* %jp{割込みサービスルーチン呼び出し} */
	if ( intno >= _KERNEL_IRCATR_TMIN_INTNO && intno <= _KERNEL_IRCATR_TMAX_INTNO )
	{
		_kernel_exe_isr(intno);
	}
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief %jp{Analog Devices ADuC7000シリーズ用割込みコントローラ操作}%en{Analog Devices ADuC7000 series}
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
	UW    intsta;
	
	switch ( inhno )
	{
	case _KERNEL_ARM_INHNO_IRQ:
		intsta = *_KERNEL_IRC_IRQSTA;
		break;

	case _KERNEL_ARM_INHNO_FIQ:
		intsta = *_KERNEL_IRC_FIQSTA;
		break;
	
	default:
		return;
	}
	
	/* %jp{割込み番号取得} */
	for ( intno = 0; intno <= 23; intno++ )
	{
		if ( intsta & 1 )
		{
			/* %jp{割込みサービスルーチン呼び出し} */
			_kernel_exe_isr(intno);
		}
		
		intsta >>= 1;
	}
}


/* end of file */

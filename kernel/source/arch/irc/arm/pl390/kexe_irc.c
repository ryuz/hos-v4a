/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの割込み処理} */
void _kernel_exe_irc(INHNO inhno)
{
	UW  intno;

	/* %jp{割込み番号取得} */
	intno = *_KERNEL_IRC_ICCIAR;
	if ( !(intno >= _KERNEL_IRCATR_TMIN_INTNO && intno <= _KERNEL_IRCATR_TMAX_INTNO) ) {
		return;
	}

	/* 優先度マスク更新 */
	UB pmr = (UB)*_KERNEL_IRC_ICCPMR;
	UB ilv = *_KERNEL_IRC_ICDIPR(intno);
	*_KERNEL_IRC_ICCPMR = ilv;

	/* 先に割り込みを終わらせる */
	*_KERNEL_IRC_ICCEOIR = intno;

	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_ictxcb.imsk &= ~_KERNEL_IMSK_I;	/* 多重割り込み許可 */
	_kernel_exe_isr((INTNO)intno);
	_kernel_ictxcb.imsk |= _KERNEL_IMSK_I;
	
	/* 優先度マスク復帰 */
	*_KERNEL_IRC_ICCPMR = pmr;
}


/* end of file */

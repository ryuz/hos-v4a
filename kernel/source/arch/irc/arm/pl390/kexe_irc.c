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
	
	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr((INTNO)intno);

	*_KERNEL_IRC_ICCEOIR = intno;
}


/* end of file */

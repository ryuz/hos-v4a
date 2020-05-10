/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
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

	/* %jp{割込み番号取得} */
	
	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr(intno);
}


/* end of file */

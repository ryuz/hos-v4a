/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kexe_irc.c
 * @brief %jp{ATMEL AT91シリーズ}%en{ATMEL AT91 series}
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
	
	/* %jp{割込み番号取得} */
	intno = *_KERNEL_IRC_AIC_IVR;
	
	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr(intno);

	/* %jp{割込み終了} */
	*_KERNEL_IRC_AIC_EOICR = 0;
}


/* end of file */

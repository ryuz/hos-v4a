/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_irc.h
 * @brief %jp{Jelly FPGAシステム}%en{Jelly FPGA}
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
	INTNO	intno;
	UW		mask;
	
	/* %jp{前処理} */
	*_KERNEL_IRC_ENABLE = 0;
	intno = *_KERNEL_IRC_REQ_FACTOR_ID;
	mask  = *_KERNEL_IRC_MASK;
	*_KERNEL_IRC_MASK = *_KERNEL_IRC_REQ_PRIORITY;
	*_KERNEL_IRC_ENABLE = 1;
	
	/* %jp{割込みサービスルーチン呼び出し} */
	_kernel_exe_isr(intno);
	
	/* %jp{割込み終了} */
	*_KERNEL_IRC_ENABLE = 0;
	*_KERNEL_IRC_MASK = mask;
	*_KERNEL_IRC_ENABLE = 1;
}


/* end of file */

/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_inte.c
 * @brief %jp{割込み処理開始}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"



/** %jp{割込み処理開始}
 * @return void
 */
void _kernel_sta_inh(void)
{
	_KERNEL_SYS_SET_CTX();
}



/* end of file */

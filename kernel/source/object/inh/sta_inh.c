/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_inte.c
 * @brief %jp{割り込み処理開始}
 *
 * @version $Id: sta_inh.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"



/** %jp{割り込み処理開始}
 * @return void
 */
void _kernel_sta_inh(void)
{
	_KERNEL_SYS_SET_CTX();
}



/* end of file */

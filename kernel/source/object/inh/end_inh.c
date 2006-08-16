/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_inte.c
 * @brief %jp{割り込み処理開始}
 *
 * @version $Id: end_inh.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"



/** %jp{割り込み処理開始}
 * @return void
 */
void _kernel_end_inh(void)
{
	_KERNEL_SYS_CLR_CTX();
	
	/* %jp{遅延しているディスパッチがあれば実施} */
	if ( _KERNEL_SYS_SNS_DLY() )
	{
		_KERNEL_SYS_CLR_DLY();
		_KERNEL_DSP_TSK();
	}
}


/* end of file */

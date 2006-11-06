/**
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_inte.c
 * @brief %jp{割り込み処理開始}
 *
 * @version $Id: end_inh.c,v 1.3 2006-11-06 15:00:59 ryuz Exp $
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
	
#if _KERNEL_SPT_DPC
	/* サービスコール内での割り込みの場合ここではディスパッチしない */
	if ( _KERNEL_SYS_REF_SVC() != 0 )
	{
		return;
	}
#endif
	
	/* %jp{遅延しているディスパッチがあれば実施} */
	if ( _KERNEL_SYS_SNS_DLY() )
	{
		_KERNEL_DSP_TSK();
	}
}


/* end of file */

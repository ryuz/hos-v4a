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


#if _KERNEL_SPT_DPC


/** %jp{割込み処理開始}
 * @return void
 */
void _kernel_end_inh(void)
{
	/* %jp{割込みコンテキストを抜ける} */
	_KERNEL_SYS_CLR_CTX();
	
	/* %jp{サービスコールの中なら何もしない} */
	if ( _KERNEL_SYS_SNS_SVC() )
	{
		return;
	}
	
	/* %jp{タスクコンテキストでDPC処理} */
	_KERNEL_ENA_INT();			/* %jp{割込み許可} */

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		
	_KERNEL_DIS_INT();			/* %jp{割込み禁止} */
}


#else


/** %jp{割込み処理開始}
 * @return void
 */
void _kernel_end_inh(void)
{
	/* %jp{割込みコンテキストを抜ける} */
	_KERNEL_SYS_CLR_CTX();
	
	/* %jp{遅延しているディスパッチがあれば実施} */
	if ( _KERNEL_SYS_SNS_DLY() )
	{
		_KERNEL_DSP_TSK();
	}
}

#endif


/* end of file */

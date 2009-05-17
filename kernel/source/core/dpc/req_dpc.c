/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/dpc.h"


#if _KERNEL_SPT_DPC


ER _kernel_req_dpc(_KERNEL_T_DPCCB *dcpcb, void (*svc)(ID id, VP_INT param1), ID id, VP_INT param)
{
	volatile _KERNEL_T_DPCMSG	*msg;
	UINT						tail;
	UINT						next_tail;
	
	_KERNEL_SYS_LOC_DPC();		/* %jp{多重割込み対策でロックをかける} */
	
	tail      = dcpcb->tail;
	next_tail = tail + 1;
	if ( next_tail >= dcpcb->quecnt )
	{
		next_tail = 0;
	}
			
	if ( next_tail == dcpcb->head )
	{
		_KERNEL_SYS_UNL_DPC();	/* %jp{ロック解除} */
		return E_NOMEM;
	}
	
	dcpcb->tail = next_tail;

	_KERNEL_SYS_UNL_DPC();		/* %jp{ロック解除} */
	
	/* %jp{実行予約} */
	msg = &dcpcb->que[tail];
	msg->svc    = svc;
	msg->id     = id;
	msg->param  = param;
	
	return E_OK;
}


#endif	/* _KERNEL_SPT_DPC */


/* end of file */

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

VP_INT _kernel_dpc_rcv_msg(_KERNEL_T_DPCCB *dcpcb)
{
	UINT   head;
	VP_INT msg;

	head = dcpcb->head;
	if ( head == dcpcb->tail )
	{
		return 0;
	}

	msg = dcpcb->msgq[head];

	if ( head + 1 >= dcpcb->msgqsz )
	{
		dcpcb->head = 0;
	}
	else
	{
		dcpcb->head = head + 1;
	}

	return msg;
}

#endif	/* _KERNEL_SPT_DPC	*/


/* end of file */

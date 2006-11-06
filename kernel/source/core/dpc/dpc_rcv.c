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



BOOL _kernel_dpc_rcv_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT *p_msg)
{
	UINT head;

	head = dcpcb->head;
	if ( head == dcpcb->tail )
	{
		return FALSE;
	}

	*p_msg = dcpcb->msgq[head];

	if ( head + 1 >= dcpcb->msgqsz )
	{
		dcpcb->head = 0;
	}
	else
	{
		dcpcb->head = head + 1;
	}

	return TRUE;
}


/* end of file */

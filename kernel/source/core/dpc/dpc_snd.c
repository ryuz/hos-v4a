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

/* %jp{メッセージの送信} */
void _kernel_dpc_snd_msg(_KERNEL_T_DPCCB *dcpcb, VP_INT msg)
{
	UINT next_tail;

	/* %jp{次の末尾位置算出} */
	if ( dcpcb->tail + 1 >= dcpcb->msgqsz )
	{
		next_tail = 0;
	}
	else
	{
		next_tail = dcpcb->tail + 1;
	}

	/* %jp{オーバーフローチェック} */
	if ( next_tail == dcpcb->head )
	{
		return;
	}

	/* %jp{格納} */
	dcpcb->msgq[dcpcb->tail] = msg;
	dcpcb->tail = next_tail;
}


#endif	/* _KERNEL_SPT_DPC	*/


/* end of file */

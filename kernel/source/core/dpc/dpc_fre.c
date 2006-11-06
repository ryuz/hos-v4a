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

/* データ数参照 */
UINT _kernel_dpc_ref_dat(_KERNEL_T_DPCCB *dcpcb)
{
	UINT head;
	UINT tail;

	head = dcpcb->head;
	tail = dcpcb->tail;

	if ( head <= tail )
	{
		return tail - head;
	}
	else
	{
		return dcpcb->msgqsz + tail - head;
	}
}


/* 空き領域の取得 */
UINT _kernel_dpc_ref_fre(_KERNEL_T_DPCCB *dcpcb)
{
	UINT head;
	UINT tail;

	head = dcpcb->head;
	tail = dcpcb->tail;

	if ( head > tail )
	{
		return head - tail - 1;
	}
	else
	{
		return dcpcb->msgqsz - tail + head  - 1;
	}
}

#endif	/* _KERNEL_SPT_DPC	*/


/* end of file */

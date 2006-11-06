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


/* end of file */

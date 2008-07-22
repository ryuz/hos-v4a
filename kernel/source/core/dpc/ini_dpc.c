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


/* 遅延プロシージャーコールの初期化 */
void _kernel_ini_dpc(_KERNEL_T_DPCCB *dcpcb, _KERNEL_T_DPCMSG *que, INT quecnt)
{
	dcpcb->que    = que;
	dcpcb->quecnt = quecnt;
	dcpcb->head   = 0;
	dcpcb->tail   = 0;
}


#endif	/* _KERNEL_SPT_DPC */


/* end of file */

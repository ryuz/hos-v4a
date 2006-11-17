/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rcv_adtq.c
 * @brief %jp{非同期データキュー受信}%en{Receive from Asynchronous Data Queue}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/adtq.h"



VP_INT _kernel_adtq_frcv_dat(_KERNEL_T_ADTQCB *adtqcb)
{
	_KERNEL_ADTQ_T_POSITION head;
	VP_INT                  *adtq;
	VP_INT                  data;

	/* %jp{先頭位置取得} */
	head = _KERNEL_ADTQ_GET_HEAD(adtqcb);
	
	/* %jp{データ取り出し} */
	adtq = _KERNEL_ADTQ_GET_ADTQ(adtqcb);
	data = adtq[head];

	/* %jp{次の末尾位置計算} */
	if ( head < _KERNEL_ADTQ_GET_ADTQCNT(adtqcb) - 1 )
	{
		head++;
	}
	else
	{
		head = 0;
	}

	/* %jp{先頭位置更新} */
	_KERNEL_ADTQ_SET_HEAD(adtqcb, head);
	
	return data;
}


/* end of file */

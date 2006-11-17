/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rcv_adtq.c
 * @brief %jp{非同期データキュー送信}%en{Send to Asynchronous Data Queue}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/adtq.h"


BOOL _kernel_adtq_snd_dat(_KERNEL_T_ADTQCB *adtqcb, VP_INT data)
{
	_KERNEL_ADTQ_T_POSITION tail;
	_KERNEL_ADTQ_T_POSITION tail_next;
	VP_INT                  *adtq;

	/* %jp{末尾位置取得} */
	tail = _KERNEL_ADTQ_GET_TAIL(adtqcb);

	/* %jp{次の末尾位置計算} */
	tail_next = tail + 1;
	if ( tail_next >= _KERNEL_ADTQ_GET_ADTQCNT(adtqcb) )
	{
		tail_next = 0;
	}

	/* %jp{空き容量} */
	if ( tail == _KERNEL_ADTQ_GET_HEAD(adtqcb) )
	{
		return FALSE;
	}
	
	/* %jp{データ格納} */
	adtq = _KERNEL_ADTQ_GET_ADTQ(adtqcb);
	adtq[tail] = data;

	/* %jp{末尾位置更新} */
	_KERNEL_ADTQ_SET_TAIL(adtqcb, tail_next);
	
	return TRUE;
}


/* end of file */


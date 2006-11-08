/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rcv_adtq.c
 * @brief %jp{非同期データキュー 送信可能データ個数参照}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/adtq.h"



_KERNEL_ADTQ_T_ADTQCNT _kernel_adtq_ref_fdtqnt(_KERNEL_T_ADTQCB *adtqcb)
{
	_KERNEL_ADTQ_T_POSITION head;
	_KERNEL_ADTQ_T_POSITION tail;

	head = _KERNEL_ADTQ_GET_HEAD(adtqcb);
	tail = _KERNEL_ADTQ_GET_TAIL(adtqcb);

	if ( tail < head )
	{
		return head - tail - 1;
	}
	else
	{
		return _KERNEL_ADTQ_GET_ADTQCNT(adtqcb) + head - tail - 1;
	}
}


/* end of file */


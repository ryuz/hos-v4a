/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  krmp_msg.c
 * @brief %jp{優先度キューからメッセージを取り出し}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


/** %jp{優先度キューからメッセージを取り出し} */
T_MSG *_kernel_rmp_msg(_KERNEL_T_MBXCB_PTR mbxcb, _KERNEL_MBXCB_T_MPRI maxmpri)
{
	_KERNEL_MBX_T_MPRI mpri;
	T_MSG              ***pppk_msgque;

	/* %jp{メッセージキューの配列として取得} */
	pppk_msgque = (T_MSG ***)_KERNEL_MBX_GET_MSGQUE(mbxcb);

	for ( mpri = 0; mpri <= maxmpri - TMIN_MPRI; mpri++ )
	{
		if ( (*pppk_msgque)[mpri] != NULL )
		{
			return _kernel_rmv_msq(&(*pppk_msgque)[mpri]);
		}
	}

	return NULL;
}


/* end of file */

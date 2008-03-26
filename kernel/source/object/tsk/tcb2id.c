/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  tcb2id.c
 * @brief %jp{TCBアドレスをIDに変換}%en{TCB-address to ID}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



#if _KERNEL_TCB_ALGORITHM == _KERNEL_TCB_ALG_PTRARRAY			/* pointer array */


/**  %jp{TCBアドレスをIDに変換}%en{TCB-address to ID} */
ID _kernel_tsk_tcb2id(_KERNEL_T_TCB *pk_tcb)
{
	ID tskid;
	
	/* %jp{テーブルを検索} */
	for ( tskid = _KERNEL_TSK_TMIN_ID; tskid <= _KERNEL_TSK_TMAX_ID; tskid++ )
	{
		if ( _KERNEL_TSK_ID2TCB(tskid) == pk_tcb )
		{
			break;
		}
	}
	
	return tskid;
}

#endif



/* end of file */

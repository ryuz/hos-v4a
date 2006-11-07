/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  krmf_msg.c
 * @brief %jp{FIFOキューからメッセージを取り出し}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


/** %jp{FIFOキューからメッセージを取り出し} */
T_MSG *_kernel_rmf_msg(_KERNEL_T_MBXCB_PTR mbxcb)
{
	T_MSG **ppk_msgque;

	/* %jp{メッセージキューを取得} */
	ppk_msgque = (T_MSG **)_KERNEL_MBX_GET_MSGQUE(mbxcb);

	if ( *ppk_msgque != NULL )
	{
		return _kernel_rmv_msq(ppk_msgque);
	}

	return NULL;
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kadf_msg.c
 * @brief %jp{FIFOキューにメッセージを追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/mbxobj.h"



/** %jp{FIFOキューにメッセージを追加} */
void _kernel_adf_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg)
{
	T_MSG **ppk_msgque;

	/* %jp{メッセージキューを取得} */
	ppk_msgque = (T_MSG **)_KERNEL_MBX_GET_MSGQUE(mbxcb);
	_kernel_add_msq(ppk_msgque, pk_msg);
}



/* end of file */

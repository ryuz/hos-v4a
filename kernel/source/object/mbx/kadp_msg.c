/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kadp_msg.c
 * @brief %jp{優先度キューにメッセージを追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/mbxobj.h"



/** %jp{優先度キューにメッセージを追加} */
void _kernel_adp_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg)
{
	_KERNEL_MBX_T_MPRI mpri;
	T_MSG              ***pppk_msgque;

	/* %jp{メッセージキューの配列として取得} */
	pppk_msgque = (T_MSG ***)_KERNEL_MBX_GET_MSGQUE(mbxcb);

	/* %jp{メッセージ優先度取得} */
	mpri = ((T_MSG_PRI *)pk_msg)->msgpri;

	/* %jp{メッセージ追加} */
	_kernel_add_msq(&(*pppk_msgque)[mpri - TMIN_MPRI], pk_msg);
}



/* end of file */

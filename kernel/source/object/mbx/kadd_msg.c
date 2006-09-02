/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_mbx.c
 * @brief %jp{メールボックス資源の返却}%en{Release Semaphore Resource}
 *
 * @version $Id: kadd_msg.c,v 1.2 2006-09-02 10:43:18 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


static void _kernel_add_mque(T_MSG **ppk_msgque, T_MSG *pk_msg);		/**< %jp{メッセージキューへのメッセージ追加} */


/** %jp{属性に応じてキューにメッセージを追加} */
void _kernel_add_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg, _KERNEL_MBX_T_MBXATR mbxatr)
{
	/* %jp{メールボックに追加} */
	if ( mbxatr & TA_MPRI )
	{
		_kernel_adp_msg(mbxcb, pk_msg);
	}
	else
	{
		_kernel_adf_msg(mbxcb, pk_msg);
	}
}


/** %jp{FIFOキューに追加} */
void _kernel_adf_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg)
{
	T_MSG **ppk_msgque;

	/* %jp{メッセージキューを取得} */
	ppk_msgque = (T_MSG **)_KERNEL_MBX_GET_MSGQUE(mbxcb);
	_kernel_add_mque(ppk_msgque, pk_msg);
}



/** %jp{優先度キューに追加} */
void _kernel_adp_msg(_KERNEL_T_MBXCB_PTR mbxcb, T_MSG *pk_msg)
{
	_KERNEL_MBX_T_MPRI mpri;
/*	T_MSG              *(*pppk_msgque)[]; <- SHのコンパイラに怒られた... orz	*/
	T_MSG              ***pppk_msgque;

	/* %jp{メッセージキューの配列として取得} */
/*	pppk_msgque = (T_MSG *(*)[])_KERNEL_MBX_GET_MSGQUE(mbxhdl);	*/
	pppk_msgque = (T_MSG ***)_KERNEL_MBX_GET_MSGQUE(mbxcb);

	/* %jp{メッセージ優先度取得} */
	mpri = ((T_MSG_PRI *)pk_msg)->msgpri;

	/* %jp{メッセージ追加} */
	_kernel_add_mque(&(*pppk_msgque)[mpri - TMIN_MPRI], pk_msg);
}



/** %jp{メッセージキューへのメッセージ追加} */
void _kernel_add_mque(T_MSG **ppk_msgque, T_MSG *pk_msg)
{
	T_MSG *msg_tail;

	msg_tail = *ppk_msgque;
	if ( msg_tail == NULL )
	{
		pk_msg->pk_next = pk_msg;
	}
	else
	{
		pk_msg->pk_next   = msg_tail->pk_next;
		msg_tail->pk_next = pk_msg;
	}

	*ppk_msgque = pk_msg;
}


/* end of file */

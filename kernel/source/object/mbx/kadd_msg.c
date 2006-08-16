/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_mbx.c
 * @brief %jp{メールボックス資源の返却}%en{Release Semaphore Resource}
 *
 * @version $Id: kadd_msg.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


static void _kernel_add_mque(T_MSG **ppk_msgque, T_MSG *pk_msg);		/**< %jp{メッセージキューへのメッセージ追加} */
static void _kernel_adp_mque(_KERNEL_T_MBXHDL mbxhdl, T_MSG *pk_msg);	/**< %jp{優先度キューに追加} */
static void _kernel_adf_mque(_KERNEL_T_MBXHDL mbxhdl, T_MSG *pk_msg);	/**< %jp{FIFOキューに追加} */



void _kernel_add_msg(_KERNEL_T_MBXHDL mbxhdl, T_MSG *pk_msg)
{
	/* %jp{メールボックに追加} */
	if ( _KERNEL_MBX_GET_MBXATR(mbxhdl) & TA_MPRI )
	{
		_kernel_adp_mque(mbxhdl, pk_msg);
	}
	else
	{
		_kernel_adf_mque(mbxhdl, pk_msg);
	}
}


/** %jp{FIFOキューに追加} */
void _kernel_adf_mque(_KERNEL_T_MBXHDL mbxhdl, T_MSG *pk_msg)
{
	T_MSG **ppk_msgque;

	/* %jp{メッセージキューを取得} */
	ppk_msgque = (T_MSG **)_KERNEL_MBX_GET_MSGQUE(mbxhdl);
	_kernel_add_mque(ppk_msgque, pk_msg);
}



/** %jp{優先度キューに追加} */
void _kernel_adp_mque(_KERNEL_T_MBXHDL mbxhdl, T_MSG *pk_msg)
{
	_KERNEL_MBX_T_MPRI mpri;
/*	T_MSG              *(*pppk_msgque)[];	*/
	T_MSG              ***pppk_msgque;

	/* %jp{メッセージキューの配列として取得} */
/*	pppk_msgque = (T_MSG *(*)[])_KERNEL_MBX_GET_MSGQUE(mbxhdl);	*/
	pppk_msgque = (T_MSG ***)_KERNEL_MBX_GET_MSGQUE(mbxhdl);

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

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_mbx.c
 * @brief %jp{メールボックス資源の返却}%en{Release Semaphore Resource}
 *
 * @version $Id: krmv_msg.c,v 1.3 2006-09-02 15:03:17 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


static T_MSG *_kernel_rmv_mque(T_MSG **ppk_msgque);		


T_MSG *_kernel_rmv_msg(_KERNEL_T_MBXCB_PTR mbxcb, _KERNEL_MBX_T_MBXATR mbxatr, _KERNEL_MBXCB_T_MPRI maxmpri)
{
	/* %jp{メールボックから取り出し} */
	if ( mbxatr & TA_MPRI )
	{
		return _kernel_rmp_msg(mbxcb, maxmpri);
	}
	else
	{
		return _kernel_rmf_msg(mbxcb);
	}
}


T_MSG *_kernel_rmf_msg(_KERNEL_T_MBXCB_PTR mbxcb)
{
	T_MSG **ppk_msgque;

	/* %jp{メッセージキューを取得} */
	ppk_msgque = (T_MSG **)_KERNEL_MBX_GET_MSGQUE(mbxcb);

	if ( *ppk_msgque != NULL )
	{
		return _kernel_rmv_mque(ppk_msgque);
	}

	return NULL;
}


T_MSG *_kernel_rmp_msg(_KERNEL_T_MBXCB_PTR mbxcb, _KERNEL_MBXCB_T_MPRI maxmpri)
{
	_KERNEL_MBX_T_MPRI mpri;
/*	T_MSG              *(*pppk_msgque)[];	やっぱりshcに怒られる... orz */
	T_MSG              ***pppk_msgque;

	/* %jp{メッセージキューの配列として取得} */
	pppk_msgque = (T_MSG ***)_KERNEL_MBX_GET_MSGQUE(mbxcb);

	for ( mpri = TMIN_MPRI; mpri < maxmpri; mpri++ )
	{
		if ( (*pppk_msgque)[mpri] != NULL )
		{
			return _kernel_rmv_mque(&(*pppk_msgque)[mpri]);
		}
	}

	return NULL;
}


/** %jp{メッセージキューからメッセージ取り出し} */
T_MSG *_kernel_rmv_mque(T_MSG **ppk_msgque)
{
	T_MSG *msg_tail;
	T_MSG *msg_head;

	msg_tail = *ppk_msgque;
	msg_head = msg_tail->pk_next;

	if ( msg_head == msg_tail )
	{
		*ppk_msgque = NULL;
	}
	else
	{
		msg_tail->pk_next = msg_head->pk_next;
	}

	return msg_head;
}

/* end of file */

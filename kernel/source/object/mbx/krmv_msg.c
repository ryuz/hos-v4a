/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sig_mbx.c
 * @brief %jp{メールボックス資源の返却}%en{Release Semaphore Resource}
 *
 * @version $Id: krmv_msg.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


static T_MSG *_kernel_rmp_mque(_KERNEL_T_MBXHDL mbxhdl);	
static T_MSG *_kernel_rmf_mque(_KERNEL_T_MBXHDL mbxhdl);	
static T_MSG *_kernel_rmv_mque(T_MSG **ppk_msgque);		



T_MSG *_kernel_rmv_msg(_KERNEL_T_MBXHDL mbxhdl)
{
	/* %jp{メールボックから取り出し} */
	if ( _KERNEL_MBX_GET_MBXATR(mbxhdl) & TA_MPRI )
	{
		return _kernel_rmp_mque(mbxhdl);
	}
	else
	{
		return _kernel_rmf_mque(mbxhdl);
	}
}


T_MSG *_kernel_rmf_mque(_KERNEL_T_MBXHDL mbxhdl)
{
	T_MSG **ppk_msgque;

	/* %jp{メッセージキューを取得} */
	ppk_msgque = (T_MSG **)_KERNEL_MBX_GET_MSGQUE(mbxhdl);

	if ( *ppk_msgque != NULL )
	{
		return _kernel_rmv_mque(ppk_msgque);
	}

	return NULL;
}


T_MSG *_kernel_rmp_mque(_KERNEL_T_MBXHDL mbxhdl)
{
#if 0
	_KERNEL_MBX_T_MPRI mpri;
	T_MSG              *(*pppk_msgque)[];

	/* %jp{メッセージキューの配列として取得} */
	pppk_msgque = (T_MSG *(*)[])_KERNEL_MBX_GET_MSGQUE(mbxhdl);

	for ( mpri = TMIN_MPRI; mpri < _KERNEL_MBX_GET_MAXMPRI(mbxhdl); mpri++ )
	{
		if ( (*pppk_msgque)[mpri] != NULL )
		{
			return _kernel_rmv_mque(&(*pppk_msgque)[mpri]);
		}
	}
#endif

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

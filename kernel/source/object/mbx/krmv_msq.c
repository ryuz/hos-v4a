/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  krmv_msq.c
 * @brief %jp{メッセージキューからメッセージ取り出し}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/mbxobj.h"


/** %jp{メッセージキューからメッセージ取り出し} */
T_MSG *_kernel_rmv_msq(T_MSG **ppk_msgque)
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

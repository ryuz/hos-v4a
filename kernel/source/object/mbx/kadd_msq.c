/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kadd_msq.c
 * @brief %jp{メッセージキューへのメッセージ追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/mbxobj.h"


/** %jp{メッセージキューへのメッセージ追加} */
void _kernel_add_msq(T_MSG **ppk_msgque, T_MSG *pk_msg)
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

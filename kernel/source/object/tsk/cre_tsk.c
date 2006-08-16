/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  act_tsk.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * @version $Id: cre_tsk.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %en{Create Task}%jp{タスクの生成}
 * @param  tskid	%jp{タスクID}%en{ID number of the task to be created}
 * @param  pk_ctsk	%jp{タスク生成情報}%en{}
 * @retval E_OK
 * @retval E_NOMEM
 */
ER cre_tsk(ID tskid, const T_CTSK *pk_ctsk)
{
	ER ercd;

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
	if ( _KERNEL_TSK_CHECK_EXS(tskid) )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_OBJ;				/* %jp{ID番号不足} */
	}
	
	/* %jp{タスク生成} */
	ercd = _kernel_cre_tsk(tskid, pk_ctsk);

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return ercd;	/* 成功 */
}



/* end of file */

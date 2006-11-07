/**
 *  Hyper Operating System V4 Advance
 *
 * @file  add_que.c
 * @brief %en{Add the task to the queue-tail}%jp{タスクをキュー末尾に追加}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"



/** %jp{タスクをキュー末尾に追加}%en{Add the task to the queue-tail}
 * @param  que   %jp{追加するキュー}%en{pointer of queue}
 * @param  ptr   %jp{追加するタスク}%en{pointer of task}
 * @param  atr   %jp{追加時の属性}%en{attribute}
 * @return void
 */
void _kernel_add_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl,
		ATR              atr)
{
	if ( atr & TA_TPRI )
	{
		_kernel_adp_que(pk_que, tskhdl);	/* %jp{タスク優先度順に追加}%en{in the order of task's priority}  */
	}
	else
	{
		_kernel_adf_que(pk_que, tskhdl);	/* %jp{FIFO順に追加}%en{in the order of FIFO} */
	}
}



/* end of file */

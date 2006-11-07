/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rot_que.c
 * @brief %en{Rotate queue}%jp{キューの回転}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"




#if _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST		/* %en{One-way list}%jp{単方向リスト} */


/** %en{Rotate Queue}%jp{キューの回転}
 * @param  que   %en{pointer of queue}%jp{回転させるキュー}
 * @return void
 */
void _kernel_rot_que(
		_KERNEL_T_QUE *pk_que)
{
	_KERNEL_T_TSKHDL tskhdl_tail;
	
	tskhdl_tail = _KERNEL_QUE_GET_TAIL(pk_que);
	
	if ( tskhdl_tail != _KERNEL_TSKHDL_NULL )
	{
		tskhdl_tail = _KERNEL_TSK_GET_QUENEXT(_KERNEL_TSK_TSKHDL2TCB(tskhdl_tail));
		_KERNEL_QUE_SET_TAIL(pk_que, tskhdl_tail);
	}
}


#elif _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST		/* %en{Two-way list}%jp{双方向リスト} */


/** %en{Rotate Queue}%jp{キューの回転}
 * @param  que   %en{pointer of queue}%jp{回転させるキュー}
 * @return void
 */
void _kernel_rot_que(
		_KERNEL_T_QUE *pk_que)
{
	_KERNEL_T_TSKHDL tskhdl_head;
	
	tskhdl_head = _KERNEL_QUE_GET_HEAD(pk_que);

	if ( tskhdl_head != _KERNEL_TSKHDL_NULL )
	{
		tskhdl_head = _KERNEL_TSK_GET_QUENEXT(_KERNEL_TSK_TSKHDL2TCB(tskhdl_head));
		_KERNEL_QUE_SET_HEAD(pk_que, tskhdl_head);
	}
}


#endif



/* end of file */

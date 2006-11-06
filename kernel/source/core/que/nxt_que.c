/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  rmh_que.h
 * @brief %jp{キュー先頭タスクの取り出し}%en{}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



#if _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_ONEWAYLIST		/* %en{One-way list} %jp{単方向リスト} */


/** %jp{キューの次のタスクの取り出し}%en{}
 * @param	pk_que  %jp{取り出すキュー}%en{queue}
 * @return	%jp{次のタスクを返す。末尾の場合は _KERNEL_TSKHDL_NULL を返す}
 */
_KERNEL_T_TSKHDL _kernel_nxt_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	/** %jp{末尾ならNULLを返す} */
	if ( tskhdl == _KERNEL_QUE_GET_TAIL(pk_que) )
	{
		return _KERNEL_TSKHDL_NULL;
	}

	/** %jp{次のタスクを返す} */
	return _KERNEL_TSK_GET_QUENEXT(_KERNEL_TSK_TSKHDL2TCB(tskhdl));
}


#elif _KERNEL_CFG_QUE_ALGORITHM == _KERNEL_QUE_ALG_TWOWAYLIST		/* %en{Two-way list} %jp{双方向リスト} */



/** %jp{キューの次のタスクの取り出し}%en{}
 * @param	pk_que  %jp{取り出すキュー}%en{queue}
 * @return	%jp{次のタスクを返す。末尾の場合は _KERNEL_TSKHDL_NULL を返す}
 */
_KERNEL_T_TSKHDL _kernel_nxt_que(
		_KERNEL_T_QUE    *pk_que,
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_TSKHDL tskhdl_next;
	_KERNEL_T_TCB    *tcb;
	
	/* %jp{TCB取得} */
	tcb = _KERNEL_TSK_TSKHDL2TCB(tskhdl);

	/** %jp{次のタスクを取得} */
	tskhdl_next = _KERNEL_TSK_GET_QUENEXT(tcb);

	/** %jp{末尾ならNULLを返す} */
	if ( tskhdl_next == _KERNEL_QUE_GET_HEAD(pk_que) )
	{
		return _KERNEL_TSKHDL_NULL;
	}

	/** %jp{次のタスクを返す} */
	return tskhdl_next;
}


#endif



/* end of file */

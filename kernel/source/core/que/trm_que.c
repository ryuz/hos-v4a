/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  knl_que.h
 * @brief %en{queue object heder file}%jp{キューオブジェクトのヘッダファイル}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"


void _kernel_trm_que(
		_KERNEL_T_TSKHDL tskhdl)
{
	_KERNEL_T_QUE *pk_que;

	pk_que = _KERNEL_TSK_GET_QUE(_KERNEL_TSK_TSKHDL2TCB(tskhdl));
	if ( pk_que != NULL )
	{
		_kernel_rmv_que(pk_que, tskhdl);
	}
}


/* end of file */

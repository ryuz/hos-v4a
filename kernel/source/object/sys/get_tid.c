/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  unl_cpu.c
 * @brief %en{Start Kernel}%jp{OSの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %jp{実行状態タスクIDの参照}
 * @return void
 */
ER get_tid(ID *p_tskid)
{
	_KERNEL_T_TSKHDL tskhdl;

	_KERNEL_ENTER_SVC();

	tskhdl = _KERNEL_SYS_GET_RUNTSK();
	
	*p_tskid = _KERNEL_TSK_TSKHDL2ID(tskhdl);

	_KERNEL_LEAVE_SVC();

	return E_OK;
}



/* end of file */

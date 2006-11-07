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



/** %jp{ディスパッチの禁止}
 * @return void
 */
ER dis_dsp(void)
{
	_KERNEL_ENTER_SVC();
	
	/* %jp{ディスパッチの禁止} */
	_KERNEL_SYS_SET_DSP();

	_KERNEL_LEAVE_SVC();

	return E_OK;	/* %jp{成功} */
}



/* end of file */

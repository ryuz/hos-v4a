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



/** %jp{ディスパッチの許可}
 * @return void
 */
ER ena_dsp(void)
{
	_KERNEL_ENTER_SVC();
	
	/* %jp{ディスパッチの許可} */
	_KERNEL_SYS_CLR_DSP();

	/* %jp{遅延しているディスパッチがあれば実施} */
	if ( _KERNEL_SYS_SNS_DLY() )
	{
		_KERNEL_DSP_TSK();
	}

	_KERNEL_LEAVE_SVC();

	return E_OK;	/* %jp{成功} */
}



/* end of file */

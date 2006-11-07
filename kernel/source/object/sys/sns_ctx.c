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



/** %jp{コンテキストの参照}
 * @return void
 */
BOOL sns_ctx(void)
{
	BOOL stat;

	_KERNEL_ENTER_SVC();
	
	stat = _KERNEL_SYS_SNS_CTX();

	_KERNEL_LEAVE_SVC();

	return stat;
}



/* end of file */

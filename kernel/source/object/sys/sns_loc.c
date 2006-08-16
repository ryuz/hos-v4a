/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  unl_cpu.c
 * @brief %en{Start Kernel}%jp{OSの起動}
 *
 * @version $Id: sns_loc.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %jp{CPUロック状態の参照}
 * @return void
 */
BOOL sns_loc(void)
{
	BOOL stat;

	_KERNEL_ENTER_SVC();
	
	stat = _KERNEL_SYS_SNS_LOC();

	_KERNEL_LEAVE_SVC();

	return stat;
}



/* end of file */

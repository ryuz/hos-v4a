/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  sta_knl.c
 * @brief %en{Start Kernel}%jp{OSの起動}
 *
 * @version $Id: loc_cpu.c,v 1.1 2006-08-16 16:27:04 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %jp{CPUのロック}
 * @return void
 */
ER loc_cpu(void)
{
	_KERNEL_ENTER_SVC();
	
	_KERNEL_SYS_SET_LOC();

	_KERNEL_LEAVE_SVC();

	return E_OK;	/* %jp{成功} */
}



/* end of file */

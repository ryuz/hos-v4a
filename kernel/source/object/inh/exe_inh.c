/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_inh.c
 * @brief %jp{割り込みハンドラの処理}
 *
 * @version $Id: exe_inh.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"



/* %jp{割り込みハンドラの処理} */
void _kernel_exe_inh(INHNO inhno)
{
	const _KERNEL_T_INHINF *pk_inhinf;
	
	pk_inhinf = _KERNEL_INT_GET_INHINF(inhno);
	
	if ( pk_inhinf->inthdr != NULL )
	{
		pk_inhinf->inthdr(inhno);
	}
}



/* end of file */

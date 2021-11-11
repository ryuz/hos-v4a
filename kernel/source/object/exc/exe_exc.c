/**
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_exc.c
 * @brief %jp{CPU例外ハンドラの処理}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/excobj.h"


/* %jp{CPU例外ハンドラの処理} */
void _kernel_exe_exh(EXCNO excno, _KERNEL_EXC_T_EXINF exinf)
{
#if _KERNEL_SPT_DEF_EXC

	/* %jp{CPU例外ハンドラの処理} */
	if ( ((VP)_KERNEL_EXC_GET_EXCHDR(excno)) != NULL )
	{
		_KERNEL_EXC_GET_EXCHDR(excno)((void *)exinf);
	}
#endif  /*  _KERNEL_SPT_DEF_EXC  */
}


/* end of file */

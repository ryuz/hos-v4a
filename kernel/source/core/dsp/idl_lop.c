/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  idl_lop.c
 * @brief %jp{アイドルループ}%en{idel loop}
 *
 * @version $Id: idl_lop.c,v 1.1 2006-08-16 16:27:03 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %jp{アイドルループ}%en{idel loop}
 * @return void
 */
void _kernel_idl_lop(void)				/**< %jp{アイドルループ}%en{idle loop} */
{
	for ( ; ; )
	{
		_kernel_wai_int();
	}
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  get_imsk.c
 * @brief %jp{割込みマスクの参照(実装依存サービスコール)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/* %jp{割込みマスクの参照(実装依存サービスコール)} */
ER get_imsk(INT *p_imsk)
{
	*p_imsk = (INT)_kernel_ictxcb.imsk;
	return E_OK;
}


/* end of file */

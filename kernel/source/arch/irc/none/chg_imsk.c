/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  chg_imsk.c
 * @brief %jp{割込みマスクの変更(実装依存サービスコール)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "kernel.h"


/* %jp{割込みマスクの変更(実装依存サービスコール)} */
ER chg_imsk(INT imsk)
{
	return E_NOSPT;
}


/* end of file */

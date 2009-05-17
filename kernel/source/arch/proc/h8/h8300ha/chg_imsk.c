/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  chg_imsk.c
 * @brief %jp{割込みマスクの変更(実装依存サービスコール)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"


/* %jp{割込みマスクの変更(実装依存サービスコール)} */
ER chg_imsk(INT imsk)
{
	if ( imsk & ~(_KERNEL_IMSK_I | _KERNEL_IMSK_UI) )
	{
		return E_PAR;
	}
	
	_kernel_dis_int();
	_kernel_ictxcb.imsk = (UB)imsk;
	_kernel_ena_int();
	
	return E_OK;
}


/* end of file */

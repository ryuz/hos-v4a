/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  get_ilv.c
 * @brief %jp{割込みレベル参照(独自サービスコール)}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "kernel.h"


/* %jp{割込みレベル参照(独自サービスコール)} */
ER vget_ilv(INTNO intno, INT *p_ilv)
{
	*p_ilv = 0;
	return E_OK;
}


/* end of file */

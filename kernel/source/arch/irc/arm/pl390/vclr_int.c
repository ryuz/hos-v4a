/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ena_int.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* %jp{割込みのクリア} */
ER vclr_int(INTNO intno)
{
	
	return E_OK;
}


/* end of file */

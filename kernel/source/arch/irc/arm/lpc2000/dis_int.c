/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dis_int.c
 * @brief %jp{Philips LPC2000ファミリ用}%en{Philips LPC2000 family}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割込みの禁止 */
ER dis_int(INTNO intno)
{
	*_KERNEL_IRC_VICIntEnClr |= (1 << intno);

	return E_OK;
}



/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ena_int.c
 * @brief %jp{ADuC7000シリーズ用割込みコントローラ操作}%en{ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/* 割り込みの許可 */
ER ena_int(INTNO intno)
{
	*_KERNEL_IRC_IRQEN |= (1 << intno);
	
	return E_OK;
}


/* end of file */

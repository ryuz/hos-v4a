/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  intc.h
 * @brief %jp{Analog Devices ADuC7000シリーズ用割込みコントローラ操作}%en{Analog Devices ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	*_KERNEL_IRC_IRQCLR = 0x00ffffff;
	*_KERNEL_IRC_FIQCLR = 0x00ffffff;
}


/* end of file */

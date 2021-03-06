/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  kini_irc.c
 * @brief %jp{ARM GIC PL390}%en{ARM GIC PL390}
 *
 * Copyright (C) 1998-2020 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	*_KERNEL_IRC_ICCPMR = 0xf8;
	*_KERNEL_IRC_ICCICR = 0x07;
}


/* end of file */

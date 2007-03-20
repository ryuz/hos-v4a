/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  intc.h
 * @brief %jp{ADuC7000シリーズ用割込みコントローラ操作}%en{ADuC7000 series}
 *
 * Copyright (C) 1998-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"
#include "aduc7000.h"


/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	IRQCLR = 0x00ffffff;
	FIQCLR = 0x00ffffff;
}


/* end of file */

/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ini_irc.c
 * @brief %jp{Philips LPC2000ファミリ用}%en{Philips LPC2000 family}
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
	int i;
	
	*_KERNEL_IRC_VICIntEnClr = 0xffffffff;
	
	for ( i = _KERNEL_IRCATR_TMIN_INTNO; i <= _KERNEL_IRCATR_TMAX_INTNO; i++ )
	{
		*_KERNEL_IRC_VICVectAddrN(i) = (UW)_kernel_irq_hdr;
	}
}


/* end of file */

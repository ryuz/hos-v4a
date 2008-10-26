/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ini_irc.c
 * @brief %jp{Jelly FPGAシステム}%en{Jelly FPGA}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"
#include "object/isrobj.h"



/** %jp{割込みコントローラの初期化} */
void _kernel_ini_irc(void)
{
	UW	maxid;
	UW	pri;
	UW	i;
	
	
	*_KERNEL_IRC_ENABLE = 0;
	
	maxid = *_KERNEL_IRC_FACTOR_ID_MAX;
	pri   = *_KERNEL_IRC_PRIORITY_MAX - 1;
	
	for ( i = 0; i <= maxid; i++ )
	{
		*_KERNEL_IRC_FACTOR_ENABLE(i)   = 0;
		*_KERNEL_IRC_FACTOR_PENDING(i)  = 0;
		*_KERNEL_IRC_FACTOR_PRIORITY(i) = pri;
	}
	
	*_KERNEL_IRC_ENABLE = 1;
}


/* end of file */

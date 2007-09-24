/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ini_irc.c
 * @brief %jp{ATMEL AT91シリーズ}%en{ATMEL AT91 series}
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
	
	*_KERNEL_IRC_AIC_IDCR = 0xffffffff;
	*_KERNEL_IRC_AIC_ICCR = 0xffffffff;
	
	for ( i = 0; i < 32; i++ )
	{
		*_KERNEL_IRC_AIC_SMR(i) = 0x00000007;
		*_KERNEL_IRC_AIC_SVR(i) = (UW)i;
	}
	
	for ( i = 0; i < 32; i++ )
	{
		*_KERNEL_IRC_AIC_EOICR = i;
	}	
}


/* end of file */

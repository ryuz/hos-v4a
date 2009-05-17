/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ini_irc.c
 * @brief %jp{Freescale MX1用}%en{Freescale MX1}
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
	/* 割込み禁止 */
	*_KERNEL_IRC_INTENABLEH  = 0x00000000;
	*_KERNEL_IRC_INTENABLEL  = 0x00000000;
	
	*_KERNEL_IRC_NIMASK      = 0x00000000;
	*_KERNEL_IRC_INTCNTL	 = 0x00180000;

	*_KERNEL_IRC_INTTYPEH    = 0x00000000;
	*_KERNEL_IRC_INTTYPEL    = 0x00000000;
	
	*_KERNEL_IRC_NIPRIORITY7 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY6 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY5 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY4 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY3 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY2 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY1 = 0xffffffff;
	*_KERNEL_IRC_NIPRIORITY0 = 0xffffffff;
	
	*_KERNEL_IRC_INTFRCH     = 0x00000000;
	*_KERNEL_IRC_INTFRCL     = 0x00000000;
}		


/* end of file */

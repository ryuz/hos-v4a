/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


SYSTIM_CPUTIME		SysTim_TimeCounter;		/* デフォルトのタイマカウンタ */


/**< タイムティクの供給(システム用) */
void SysTim_Signal(unsigned long ulTic)
{
	SysTim_TimeCounter += ulTic;
	
	isig_tim();
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "sysapi_local.h"


/* 時間待ち */
void SysTim_Wait(unsigned long ulTime)
{
	dly_tsk((RELTIM)ulTime);
}


TIME SysTim_GetCurrentTime(void)
{
	SYSTIM tim;
	get_tim(&tim);	
	return tim;
}


/* end of file */

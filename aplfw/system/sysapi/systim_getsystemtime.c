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


/* システム時刻取得 */
TIME SysTim_GetSystemTime(void)
{
	SYSTIM tim;
	get_tim(&tim);	
	return tim;
}


/* end of file */

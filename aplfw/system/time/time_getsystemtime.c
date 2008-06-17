/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  time.h
 * @brief %jp{時刻管理API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "time.h"
#include "system/sysapi/sysapi.h"


/* システム時刻(起動からのミリ秒)を得る */
TIME_SYSTEM Time_GetSystemTime(void)
{
	SYSTIM_SYSTIME	SysTime;

	SysTime = SysTim_GetSystemTime();
	
	return (SysTim_SysTimeToSecond(SysTime) * 1000) + (SysTim_SysTimeToNanosecond(SysTime) / 1000000);
}


/* end of file */

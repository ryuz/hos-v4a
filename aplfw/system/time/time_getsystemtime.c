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
	return SysTim_GetSystemTime();
}


/* end of file */

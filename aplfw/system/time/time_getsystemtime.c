/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  time.h
 * @brief %jp{サ込理APIトチ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */
 

#include "time.h"
#include "system/sysapi/sysapi.h"


/* ・キ・ケ・ニ・狃刻(オッニー、ォ、鬢ホ・゜・テ)、る */
TIME_SYSTEM Time_GetSystemTime(void)
{
	return SysTim_GetSystemTime();
}


/* end of file */

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


/* 一定時刻待つ */
void Time_Wait(TIME_SYSTEM Millisecond)
{
	SysTim_Wait(Millisecond);
}


/* end of file */

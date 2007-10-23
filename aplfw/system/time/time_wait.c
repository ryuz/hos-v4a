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


/* ー込*/
void Time_Wait(TIME_SYSTEM Millisecond)
{
	SysTim_Wait(Millisecond);
}


/* end of file */

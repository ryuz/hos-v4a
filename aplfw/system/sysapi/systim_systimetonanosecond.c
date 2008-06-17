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



/* システム時刻の単位に応じてオーバーライドすること */


/** システム時刻をナノ秒に換算(システム用) */
unsigned long SysTim_SysTimeToNanosecond(SYSTIM_SYSTIME SysTime)
{
	return (unsigned long)(SysTime % 1000 * 1000000);		/* デフォルトではミリ秒単位から変換 */
}


/* end of file */

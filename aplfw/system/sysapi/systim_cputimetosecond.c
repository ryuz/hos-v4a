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


/* SysTim_GetCpuTime をオーバーライドする場合は一緒に
  オーバーライドすること */


/* CPU時刻を秒に換算(システム用) */
unsigned long  SysTim_CpuTimeToSecond(SYSTIM_CPUTIME CpuTime)
{
	/* デフォルトではシステム時刻と同じ単位 */
	return SysTim_SysTimeToSecond((SYSTIM_SYSTIME)CpuTime);
}


/* end of file */

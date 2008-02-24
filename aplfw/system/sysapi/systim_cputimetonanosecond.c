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


/** CPU時刻をナノ秒に換算(システム用) */
unsigned long SysTim_CpuTimeToNanosecond(SYSTIM_CPUTIME CpuTime)
{
	return (unsigned long)(CpuTime % 1000000000UL);		/* デフォルトではナノ秒単位 */
}


/* end of file */

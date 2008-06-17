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


/* 精度の良いタイマを持ったシステムでは本関数を
  オーバーライドすることで、高精度のCPU時刻計測が可能となる */


/**< 現在のCPU時刻取得(システム用) */
SYSTIM_CPUTIME SysTim_GetCpuTime(void)
{
	return SysTim_TimeCounter;
}


/* end of file */

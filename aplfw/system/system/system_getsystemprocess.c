/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/system/system_local.h"



/* システムプロセスを得る */
C_PROCESS *System_GetSystemProcess(void)
{
	return &g_System.Process;
}



/* end of file */

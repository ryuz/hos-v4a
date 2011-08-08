/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2011 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/sysapi/sysapi.h"
#include "system/system/system_local.h"
#include "system/process/process_local.h"


/* プロセスの登録解除 */
void System_UnregistryProcess(unsigned long ulProcessId)
{
	C_SYSTEM		*self;

	self = &g_System;

	self->ppProcessTable[ulProcessId % self->ulProcessTableSize] = NULL;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  system.h
 * @brief %jp{システム用API定義}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/sysapi/sysapi.h"
#include "system/system/system_local.h"
#include "system/process/process_local.h"


/* 登録オブジェクトの取得 */
C_PROCESSOBJ *System_GetProcessObj(unsigned long ulProcessId)
{
	C_SYSTEM		*self;
	C_PROCESSOBJ	*pProcessObj;
	

	self = &g_System;
	
	pProcessObj = self->ppProcessTable[ulProcessId % self->ulProcessTableSize];
	if ( pProcessObj->ulProcessId != ulProcessId )
	{
		return NULL;
	}

	return pProcessObj;
}


/* end of file */

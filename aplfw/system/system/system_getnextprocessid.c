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


/* 次のプロセスを取得 */
unsigned long System_GetNextProcessId(unsigned long ulProcessId)
{
	unsigned long	ulNextId = 0;
	unsigned long	ulId;
	C_SYSTEM		*self;
	
	self = &g_System;
	
	SysMtx_Lock(self->hMtxSys);
	
	ulId = (ulProcessId % self->ulProcessTableSize) + 1;
	for ( ; ulId < self->ulProcessTableSize; ulId++ )
	{
		if ( self->ppProcessTable[ulId] != NULL )
		{
			ulNextId = self->ppProcessTable[ulId]->ulProcessId;
			break;
		}
	}

	SysMtx_Unlock(self->hMtxSys);

	return ulNextId;
}


/* end of file */

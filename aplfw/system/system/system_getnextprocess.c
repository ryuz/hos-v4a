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


/* プロセスの登録 */
unsigned long System_RegistryProcess(C_PROCESSOBJ *pProcessObj)
{
	unsigned long	ulSysPrcId;
	unsigned long	ulProcessId;
	C_SYSTEM		*self;

	self = &g_System;

	/* ITRON-ID取得 */
	ulSysPrcId = (unsigned long)pProcessObj->hPrc;
	SYS_ASSERT(ulSysPrcId < self->ulProcessTableSize);
	SYS_ASSERT(self->ppProcessTable[ulSysPrcId] == NULL);

	/* 重複しないIDを計算(但し一意に元IDを手繰れる数とする) */
	ulProcessId  = self->ulNextProcessId - (self->ulNextProcessId % self->ulProcessTableSize);
	ulProcessId += ulSysPrcId;
	if ( ulProcessId < self->ulNextProcessId )
	{
		ulProcessId += self->ulProcessTableSize;
	}

	self->ppProcessTable[ulSysPrcId] = pProcessObj;
	self->ulNextProcessId = ulProcessId + 1;

	return ulProcessId;
}


/* プロセスの登録解除 */
void System_UnregistryProcess(unsigned long ulProcessId)
{
	C_SYSTEM		*self;

	self = &g_System;

	self->ppProcessTable[ulProcessId % self->ulProcessTableSize] = NULL;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "memdrv_local.h"
#include "system/sysapi/sysapi.h"



/** オープン */
HANDLE MemDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_MEMDRV		*self;
	C_MEMDRVFILE	*pFile;
	
	/* upper cast */
	self = (C_MEMDRV *)pDrvObj;
	
	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(C_MEMDRVFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	FileObj_Create(&pFile->FileObj, pDrvObj, NULL);
	pFile->FilePos = 0;

	/* オープン処理 */
	SysMtx_Lock(self->hMtx);
	self->iOpenCount++;
	SysMtx_Unlock(self->hMtx);
	
	return (HANDLE)pFile;
}


/* end of file */

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
#include "memfile.h"


/** オープン */
HANDLE MemDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_MEMDRV	*self;
	HANDLE		hFile;
	
	/* upper cast */
	self = (C_MEMDRV *)pDrvObj;

	SysMtx_Lock(self->hMtx);
	
	/* create file descriptor */
	hFile = MemFile_Create(self, iMode);
	if ( hFile == HANDLE_NULL )
	{
		SysMtx_Unlock(self->hMtx);
		return HANDLE_NULL;
	}
	
	if ( iMode & FILE_OPEN_CREATE )
	{
		self->FileSize = 0;
	}
	
	/* オープン処理 */
	self->iOpenCount++;

	SysMtx_Unlock(self->hMtx);
	
	return hFile;
}


/* end of file */

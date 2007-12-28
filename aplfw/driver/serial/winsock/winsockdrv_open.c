/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  winsockdrv.h
 * @brief %jp{WinSockでシリアルを擬似するドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "winsockdrv_local.h"


/** オープン */
HANDLE WinSockDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_WINSOCKDRV		*self;
	HANDLE				hFile;

	/* upper cast */
	self = (C_WINSOCKDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}

	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
	}

	return hFile;
}


/* end of file */

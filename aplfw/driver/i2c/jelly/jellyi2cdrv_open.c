/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_open.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


/** オープン */
HANDLE JellyI2cDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_JELLYI2CDRV	*self;
	HANDLE			hFile;
	
	/* upper cast */
	self = (C_JELLYI2CDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	self->iOpenCount++;
	
	return hFile;
}


/* end of file */

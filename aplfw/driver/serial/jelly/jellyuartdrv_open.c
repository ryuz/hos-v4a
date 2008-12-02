/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_close.c
 * @brief %jp{JellyUart クローズ}%en{JellyUart  close}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"


/** オープン */
HANDLE JellyUartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_JELLYUARTDRV	*self;
	HANDLE		hFile;
	
	/* upper cast */
	self = (C_JELLYUARTDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		/* 受信割込みを許可 */
		SysInt_Enable(self->iIntNumRx);
	}
	
	return hFile;
}


/* end of file */

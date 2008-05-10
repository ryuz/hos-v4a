/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_close.c
 * @brief %jp{PC/AT text mode driver クローズ}%en{PC/AT text mode driver  close}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


/** オープン */
HANDLE PcatTextDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_PCATTEXTDRV	*self;
	HANDLE			hFile;
	
	/* upper cast */
	self = (C_PCATTEXTDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = FileObj_Create(&self->DrvObj, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		/* ここでデバイスを初期化 */
	}
	
	return hFile;
}


/* end of file */

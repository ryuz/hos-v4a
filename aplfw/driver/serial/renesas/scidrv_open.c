/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** オープン */
HANDLE SciDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_SCIDRV	*self;
	HANDLE		hFile;
	
	/* upper cast */
	self = (C_SCIDRV *)pDrvObj;
	
	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		SciHal_Setup(&self->SciHal);
		SciHal_SetSpeed(&self->SciHal, 38400);
		SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_RIE);
	}

	return hFile;
}


/* end of file */

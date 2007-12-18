/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** オープン */
HANDLE SciDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_SCIDRV	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self = (C_SCIDRV *)pDrvObj;

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(*pFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	SyncFile_Create(pFile, &self->SyncDrv, NULL);
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		SciHal_Setup(&self->SciHal);
		SciHal_SetSpeed(&self->SciHal, 38400);
		SciHal_EnableInterrupt(&self->SciHal, SCIHAL_INT_RIE);
	}

	return (HANDLE)pFile;
}


/* end of file */

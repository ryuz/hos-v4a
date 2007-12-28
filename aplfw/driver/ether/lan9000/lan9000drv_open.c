/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{LAN9000用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


/** オープン */
HANDLE Lan9000Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_LAN9000DRV	*self;
	HANDLE			hFile;
	
	/* upper cast */
	self = (C_LAN9000DRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}

	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		Lan9000Hal_Setup(&self->Lan9000Hal);
		Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, LAN9000HAL_IMASK_RCVINT);
		SysInt_Enable(self->iIntNum);
	}
	
	return hFile;
}


/* end of file */

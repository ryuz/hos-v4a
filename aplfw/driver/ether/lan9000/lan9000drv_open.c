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
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self = (C_LAN9000DRV *)pDrvObj;

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(C_SYNCFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	SyncFile_Create(pFile, &self->SyncDrv, NULL);

	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		Lan9000Hal_Setup(&self->Lan9000Hal);
		Lan9000Hal_SetInterruptMask(&self->Lan9000Hal, LAN9000HAL_IMASK_RCVINT);
		SysInt_Enable(self->iIntNum);
	}
	
	return (HANDLE)pFile;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/** オープン */
HANDLE Pc16550Drv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_PC16550DRV	*self;
	C_CHRFILE		*pFile;
	
	/* upper cast */
	self = (C_PC16550DRV *)pDrvObj;

	/* create file descriptor */
	if ( (pFile = SysMem_Alloc(sizeof(*pFile))) == NULL )
	{
		return HANDLE_NULL;
	}
	ChrFile_Create(pFile, &self->ChrDrv, NULL);

	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		Pc16550Hal_Setup(&self->Pc16550Hal);
		Pc16550Hal_SetSpeed(&self->Pc16550Hal, 38400);
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, PC16550HAL_IER_ERBFI);
		SysInt_Enable(self->iIntNum);
	}

	return (HANDLE)pFile;
}


/* end of file */

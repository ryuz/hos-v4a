/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_close.c
 * @brief %jp{XILINX UART driver クローズ}%en{XILINX UART driver  close}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"


/** オープン */
HANDLE XilinxUartDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_XILINXUARTDRV	*self;
	HANDLE		hFile;
	
	/* upper cast */
	self = (C_XILINXUARTDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, iMode)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		/* ここでデバイスを初期化 */
		XILINXUARTDRV_REG_WRITE(self, XILINXUARTDRV_REG_CTRL, 0x03);	/* FIFO clear */
		XILINXUARTDRV_REG_WRITE(self, XILINXUARTDRV_REG_CTRL, 0x10);	/* Enable Int */

		/* 割込みを許可 */
		SysInt_Enable(self->iIntNum);
	}
	
	return hFile;
}


/* end of file */

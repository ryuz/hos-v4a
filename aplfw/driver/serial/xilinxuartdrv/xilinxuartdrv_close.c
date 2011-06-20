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


/** クローズ */
void XilinxUartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_XILINXUARTDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_XILINXUARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		XILINXUARTDRV_REG_WRITE(self, XILINXUARTDRV_REG_CTRL, 0x00);	/* Disable Int */
		SysInt_Disable(self->iIntNum);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete((HANDLE)pFile);	
}


/* end of file */

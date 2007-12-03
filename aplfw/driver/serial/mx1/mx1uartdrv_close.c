/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_close.h
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/** クローズ */
void Mx1UartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_MX1UARTDRV	*self;
	C_CHRFILE		*pFile;
	
	/* upper cast */
	self  = (C_MX1UARTDRV *)pDrvObj;
	pFile = (C_CHRFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	ChrFile_Delete(pFile);	
	SysMem_Free(pFileObj);
}


/* end of file */

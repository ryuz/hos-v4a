/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_close.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


/** クローズ */
void At91UartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_AT91UARTDRV	*self;
	C_CHRFILE		*pChrFile;
	
	/* upper cast */
	self     = (C_AT91UARTDRV *)pDrvObj;
	pChrFile = (C_CHRFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		StreamBuf_ClearBuf(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	ChrFile_Delete(pChrFile);	
	SysMem_Free(pFileObj);
}


/* end of file */

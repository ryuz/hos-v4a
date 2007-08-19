/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_close.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** クローズ */
void At91UsartDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_AT91USARTDRV	*self;
	C_CHRFILE		*pChrFile;
	
	/* upper cast */
	self     = (C_AT91USARTDRV *)pDrvObj;
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

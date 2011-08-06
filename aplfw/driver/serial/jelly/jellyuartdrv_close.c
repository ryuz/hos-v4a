/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_close.c
 * @brief %jp{JellyUart クローズ}%en{JellyUart  close}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"


/** クローズ */
void JellyUartDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_JELLYUARTDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_JELLYUARTDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNumRx);
		SysInt_Disable(self->iIntNumTx);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete((HANDLE)pFile);	
}


/* end of file */

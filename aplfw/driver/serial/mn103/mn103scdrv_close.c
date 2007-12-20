/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_close.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/** クローズ */
void Mn103ScDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_MN103SCDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_MN103SCDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNumTx);
		SysInt_Disable(self->iIntNumRx);

		MN103SC_WRITE_CTR(self, 0x0000);	/* 停止 */

		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete((HANDLE)pFile);	
}


/* end of file */

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


/** クローズ */
void Pc16550Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_PC16550DRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_PC16550DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		Pc16550Hal_EnableInterrupt(&self->Pc16550Hal, 0);
		Pc16550Hal_Stop(&self->Pc16550Hal);
		StreamBuf_Clear(&self->StmBufRecv);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete(pFile);	
}


/* end of file */

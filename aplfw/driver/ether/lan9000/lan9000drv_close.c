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


/** クローズ */
void Lan9000Drv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_LAN9000DRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_LAN9000DRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
		Lan9000Hal_Stop(&self->Lan9000Hal);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete(pFile);	
	SysMem_Free(pFileObj);
}


/* end of file */

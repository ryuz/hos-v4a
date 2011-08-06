/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_close.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/** クローズ */
void Lan9118Drv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_LAN9118DRV	*self;
	C_CHRFILE		*pFile;
	
	/* upper cast */
	self  = (C_LAN9118DRV *)pFileObj;
	pFile = (C_CHRFILE *)pFilePtr;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		SysInt_Disable(self->iIntNum);
	}
	
	/* ディスクリプタ削除 */
	ChrFile_Delete(pFile);	
	SysMem_Free(pFilePtr);
}


/* end of file */

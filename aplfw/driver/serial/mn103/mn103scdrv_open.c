/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_open.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/** オープン */
HANDLE Mn103ScDrv_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_MN103SCDRV	*self;
	HANDLE			hFile;
	
	/* upper cast */
	self = (C_MN103SCDRV *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv, 3)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		MN103SC_WRITE_CTR(self, 0xc083);	/* 設定 */

		SysInt_Enable(self->iIntNumRx);		/* 受信割込みを許可 */
	}
	
	return hFile;
}


/* end of file */

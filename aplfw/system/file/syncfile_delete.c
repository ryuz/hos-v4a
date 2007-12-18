/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncfile.h
 * @brief %jp{同期機能付きデバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "syncfile.h"
#include "syncdrv.h"


void SyncFile_Delete(C_SYNCFILE *self)
{
	struct c_syncdrv *pSyncDrv;
	
	pSyncDrv = (struct c_syncdrv *)self->FileObj.pDrvObj;
	
	
	/* リスト連結解除 */
	SysMtx_Lock(pSyncDrv->hMtx);
	if ( self->pNext == self )
	{
		pSyncDrv->pFileHead = NULL;
	}
	else
	{
		if ( pSyncDrv->pFileHead == self )
		{
			pSyncDrv->pFileHead = self->pNext;
		}
		self->pNext->pPrev = self->pPrev;
		self->pPrev->pNext = self->pNext;
	}
	SysMtx_Unlock(pSyncDrv->hMtx);	
	
	
	/* 親クラスデストラクタ呼び出し */
	FileObj_Delete(&self->FileObj);
}


/* end of file */

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



#include "syncfile_local.h"


void SyncFile_Destructor(C_SYNCFILE *self)
{
	C_SYNCDRV	*pSyncDrv;
	int			iFactorNum;
	int			i;

	pSyncDrv = (C_SYNCDRV *)self->FileObj.pDrvObj;

	/* 同期要因数取得 */
	iFactorNum = SyncDrv_GetSyncFactorNum(pSyncDrv);
	
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
	
	
	/* オブジェクト削除 */
	for ( i = 0; i < iFactorNum; i++ )
	{
		SysEvt_Delete(self->pSyncObj[i].hEvt);
	}

	/* メモリ開放 */
	SysMem_Free(self->pSyncObj);
	
	/* 親クラスデストラクタ呼び出し */
	FileObj_Destructor(&self->FileObj);
}


/* end of file */

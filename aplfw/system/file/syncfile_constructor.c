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


FILE_ERR SyncFile_Constructor(C_SYNCFILE *self, const T_FILEOBJ_METHODS *pMethods, struct c_syncdrv *pSyncDrv, int iMode)
{
	int iFactorNum;
	int i;
	
	/* 同期要因数取得 */
	iFactorNum = SyncDrv_GetSyncFactorNum(pSyncDrv);
	
	/* メモリ確保 */
	if ( (self->pSyncObj = (T_SYNCFILE_SYNCOBJ *)SysMem_Alloc(sizeof(T_SYNCFILE_SYNCOBJ) * iFactorNum)) == NULL )
	{
		return FILE_ERR_NG;
	}

	/* 親クラスコンストラクタ呼び出し */
	FileObj_Constructor(&self->FileObj, pMethods, &pSyncDrv->DrvObj, iMode);
	
	/* メンバ初期化 */
	for ( i = 0; i < iFactorNum; i++ )
	{
		self->pSyncObj[i].Mode     = FILE_SYNCMODE_BLOCKING;
		self->pSyncObj[i].hEvt     = SysEvt_Create(SYSEVT_ATTR_NORMAL);
		self->pSyncObj[i].ErrCode  = FILE_ERR_OK;
		self->pSyncObj[i].Inf.Type = FILE_SYNCTYPE_NONE;
	}
	
	/* リスト連結 */
	SysMtx_Lock(pSyncDrv->hMtx);
	if ( pSyncDrv->pFileHead == NULL )
	{
		self->pNext        = self;	
		self->pPrev        = self;
		pSyncDrv->pFileHead = self;
	}
	else
	{
		self->pNext = pSyncDrv->pFileHead;	
		self->pPrev = self->pNext->pPrev;
		self->pNext->pPrev = self;
		self->pPrev->pNext = self;
	}
	SysMtx_Unlock(pSyncDrv->hMtx);
	
	return FILE_ERR_OK;
}


/* end of file */

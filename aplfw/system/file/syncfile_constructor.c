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


void SyncFile_Constructor(C_SYNCFILE *self, const T_FILEOBJ_METHODS *pMethods, struct c_syncdrv *pSyncDrv)
{
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Constructor(&self->FileObj, pMethods, &pSyncDrv->DrvObj);
	
	/* メンバ初期化 */	
	self->cWriteMode  = FILE_WMODE_BLOCKING;
	self->cReadMode   = FILE_RMODE_BLOCKING;
	self->cIoMode     = FILE_IMODE_BLOCKING;
	self->hEventWrite = HANDLE_NULL;	
	self->hEventRead  = HANDLE_NULL;	
	self->hEventIo    = HANDLE_NULL;
	self->hPrcWrite   = SYSPRC_HANDLE_NULL;
	self->hPrcRead    = SYSPRC_HANDLE_NULL;
	self->hPrcIo      = SYSPRC_HANDLE_NULL;
		
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
}


/* end of file */

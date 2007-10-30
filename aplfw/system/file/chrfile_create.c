/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrfile.h
 * @brief %jp{キャラクタ型デバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "chrfile.h"
#include "chrdrv.h"


void ChrFile_Create(C_CHRFILE *self, struct c_chrdrv *pChrDrv, const T_FILEOBJ_METHODS *pMethods)
{
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, &pChrDrv->DrvObj, pMethods);

	/* メンバ初期化 */	
	self->hEventWrite = HANDLE_NULL;	
	self->hEventRead  = HANDLE_NULL;	
	self->cWriteMode  = FILE_WMODE_BLOCKING;
	self->cReadMode   = FILE_RMODE_BLOCKING;
	
	/* リスト連結 */
	SysMtx_Lock(pChrDrv->hMtx);
	if ( pChrDrv->pFileHead == NULL )
	{
		self->pNext        = self;	
		self->pPrev        = self;
		pChrDrv->pFileHead = self;
	}
	else
	{
		self->pNext = pChrDrv->pFileHead;	
		self->pPrev = self->pNext->pPrev;
		self->pNext->pPrev = self;
		self->pPrev->pNext = self;
	}
	SysMtx_Unlock(pChrDrv->hMtx);	
}


/* end of file */

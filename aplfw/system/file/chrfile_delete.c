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


void ChrFile_Delete(C_CHRFILE *self)
{
	struct c_chrdrv *pChrDrv;
	
	pChrDrv = (struct c_chrdrv *)self->FileObj.pDrvObj;
	
	
	/* リスト連結解除 */
	SysMtx_Lock(pChrDrv->hMtx);
	if ( self->pNext == self )
	{
		pChrDrv->pFileHead = NULL;
	}
	else
	{
		if ( pChrDrv->pFileHead == self )
		{
			pChrDrv->pFileHead = self->pNext;
		}
		self->pNext->pPrev = self->pPrev;
		self->pPrev->pNext = self->pNext;
	}
	SysMtx_Unlock(pChrDrv->hMtx);	
	
	
	/* 親クラスデストラクタ呼び出し */
	FileObj_Delete(&self->FileObj);
}


/* end of file */

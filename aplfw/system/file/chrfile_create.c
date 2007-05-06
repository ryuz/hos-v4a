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


void ChrFile_Create(C_CHRFILE *self, struct c_drvobj *pDrvObj, const T_FILEOBJ_METHODS *pMethods)
{
	/* 親クラスコンストラクタ呼び出し */
	FileObj_Create(&self->FileObj, pDrvObj, pMethods);

	/* メンバ初期化 */	
	self->pMonNext   = NULL;	
	self->pMonPrev   = NULL;
	self->hEvntWrite = HANDLE_NULL;	
	self->hEvntRead  = HANDLE_NULL;	
	self->cWriteMode = FILE_WMODE_BLOCKING;
	self->cReadMode  = FILE_RMODE_BLOCKING;
}


/* end of file */

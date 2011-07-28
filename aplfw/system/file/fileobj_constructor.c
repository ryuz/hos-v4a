/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "system/system/system_local.h"
#include "fileobj_local.h"


/* コンストラクタ */
void FileObj_Constructor(C_FILEOBJ *self, const T_FILEOBJ_METHODS *pMethods, C_DRVOBJ *pDrvObj, int iMode)
{
	/* 親クラスコンストラクタ呼び出し */
	TargetObj_Constructor(&self->TargetObj, &pMethods->HandlObjMethods, &System_GetSystemProcess()->OwnerObj);
	
	/* メンバ変数初期化 */
	self->pDrvObj   = pDrvObj;
	self->iMode     = iMode;
	self->pReadBuf  = NULL;
	self->pWriteBuf = NULL;
}


/* end of file */

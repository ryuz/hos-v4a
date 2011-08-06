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
#include "file_local.h"


/* コンストラクタ */
void FilePtr_Constructor(C_FILEPTR *self, const T_FILEOBJ_METHODS *pMethods, C_FILEOBJ *pFileObj, int iMode)
{
	/* 親クラスコンストラクタ呼び出し */
	PointerObj_Constructor(&self->PointerObj, &pMethods->ObjectMethods, &pFileObj->TargetObj);
	
	/* メンバ変数初期化 */
	self->iMode     = iMode;
	self->pReadBuf  = NULL;
	self->pWriteBuf = NULL;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fileobj_local.h"


/* コンストラクタ */
void FileObj_Constructor(C_FILEOBJ *self, const T_FILEOBJ_METHODS *pMethods, C_DRVOBJ *pDrvObj)
{
	/* 親クラスコンストラクタ呼び出し */
	HandleObj_Constructor(&self->HandleObj, &pMethods->HandlObjMethods);
	
	/* メンバ変数初期化 */
	self->pDrvObj = pDrvObj;
}


/* end of file */

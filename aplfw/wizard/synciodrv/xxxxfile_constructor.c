/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxfile_constructor.c
 * @brief %jp{$OBJNAME_JP$ コンストラクタ}%en{$OBJNAME_EN$  constructor}
 *
 * $COPYRIGHT$
 */


#include "xxxxfile_local.h"


void XxxxFile_Constructor(C_XXXXFILE *self, const T_FILEOBJ_METHODS *pMethods, C_XXXXDRV *pXxxxDrv, int iMode)
{
	/* 親クラスコンストラクタ */
	SyncFile_Constructor(&self->SyncFile, pMethods, &pXxxxDrv->SyncDrv, iMode);
	
	/* メンバ変数初期化 */
}


/* end of file */

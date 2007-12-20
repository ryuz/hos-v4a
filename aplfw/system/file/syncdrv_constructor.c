/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncdrv.h
 * @brief %jp{同期機能付きデバイスドライバ用基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "syncdrv_local.h"


FILE_ERR SyncDrv_Constructor(C_SYNCDRV *self, const T_DRVOBJ_METHODS *pMethods, int iSyncFactorNum)
{
	int i;
	
	/* メモリ確保 */
	if ( (self->ppBusyFile = (C_SYNCFILE **)SysMem_Alloc(sizeof(C_SYNCFILE *) * iSyncFactorNum)) == NULL )
	{
		return FILE_ERR_NG;
	}

	/* 排他制御ミューテックス生成 */
	self->hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* メンバ変数初期化 */
	self->pFileHead      = NULL;
	self->iSyncFactorNum = iSyncFactorNum;
	for ( i = 0; i < self->iSyncFactorNum; i++ )
	{
		self->ppBusyFile[i] = NULL;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Constructor(&self->DrvObj, pMethods);
	
	return FILE_ERR_OK;
}


/* end of file */

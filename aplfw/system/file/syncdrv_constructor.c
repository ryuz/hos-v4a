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


FILE_ERR SyncDrv_Constructor(C_SYNCDRV *self, const T_DRVOBJ_METHODS *pMethods)
{
	/* メンバ変数初期化 */
	self->iStatus   = SYNCDRV_STATUS_WRITE | SYNCDRV_STATUS_READ | SYNCDRV_STATUS_IO;	/* ステータス */
	self->pFileHead = NULL;															/* 状態監視オブジェクトの連結ポインタ */

	/* 排他制御ミューテックス生成 */
	self->hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Constructor(&self->DrvObj, pMethods);
	
	return FILE_ERR_OK;
}


/* end of file */

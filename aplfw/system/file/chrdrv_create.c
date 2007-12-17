/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrdrv.h
 * @brief %jp{キャラクタ型デバイスドライバ用基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "chrdrv_local.h"


FILE_ERR ChrDrv_Create(C_CHRDRV *self, const T_DRVOBJ_METHODS *pMethods)
{
	/* メンバ変数初期化 */
	self->iStatus   = CHRDRV_STATUS_WRITE | CHRDRV_STATUS_READ | CHRDRV_STATUS_IO;	/* ステータス */
	self->pFileHead = NULL;															/* 状態監視オブジェクトの連結ポインタ */

	/* 排他制御ミューテックス生成 */
	self->hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Create(&self->DrvObj, pMethods);
	
	return FILE_ERR_OK;
}


/* end of file */

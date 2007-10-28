/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrdrv.h
 * @brief %jp{キャラクタ型デバイスドライバ用基本クラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "chrdrv.h"


FILE_ERR ChrDrv_Create(C_CHRDRV *self, const T_DRVOBJ_METHODS *pMethods)
{
	self->hMtx      = SysMtx_Create();		/* 排他制御ミューテックス */
	self->hEvtWrite = SysEvt_Create();		/* 書込みイベント */
	self->hEvtRead  = SysEvt_Create();		/* 読込みイベント */
	
	self->pFileHead = NULL;					/**< 状態監視オブジェクトの連結ポインタ */

	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Create(&self->DrvObj, pMethods);
	
	return FILE_ERR_OK;
}


/* end of file */

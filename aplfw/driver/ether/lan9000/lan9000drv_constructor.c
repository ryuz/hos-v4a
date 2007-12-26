/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"



/** コンストラクタ */
FILE_ERR Lan9000Drv_Constructor(C_LAN9000DRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum)
{
	FILE_ERR	ErrCode;

	/* 親クラスコンストラクタ呼び出し */
	if ( (ErrCode = SyncDrv_Constructor(&self->SyncDrv, pMethods, SYNCDRV_FACTOR_NUM)) != FILE_ERR_OK )
	{
		return ErrCode;
	}
	
	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	
	/* Lan9000Hal 初期化 */
	Lan9000Hal_Create(&self->Lan9000Hal, pRegBase);

	/* ミューテックス生成 */
	self->hMtx = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	self->hIsr = SysIsr_Create(iIntNum, Lan9000Drv_Isr, (VPARAM)self);
	
	return FILE_ERR_OK;
}


/* end of file */

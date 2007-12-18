/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_create.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Lan9118Drv_Methods = 
	{
		Lan9118Drv_Delete,
		Lan9118Drv_Open,
		Lan9118Drv_Close,
		Lan9118Drv_IoControl,
		Lan9118Drv_Seek,
		Lan9118Drv_Read,
		Lan9118Drv_Write,
		Lan9118Drv_Flush,
	};


/** コンストラクタ */
void Lan9118Drv_Create(C_LAN9118DRV *self, void *pRegBase, int iIntNum)
{
	/* 親クラスコンストラクタ呼び出し */
	SyncDrv_Create(&self->SyncDrv, &Lan9118Drv_Methods);

	/* メンバ変数初期化 */
	self->pRegBase    = pRegBase;
	self->iIntNum     = iIntNum;
	self->iOpenCount  = 0;
	
	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
	self->hEvtSend = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->hMtxRecv = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	SysIsr_Create(iIntNum, Lan9118Drv_Isr, (VPARAM)self);
}


/* end of file */

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


/* 仮想関数テーブル */
static const T_DRVOBJ_METHODS Lan9000Drv_Methods = 
	{
		Lan9000Drv_Delete,
		Lan9000Drv_Open,
		Lan9000Drv_Close,
		Lan9000Drv_IoControl,
		Lan9000Drv_Seek,
		Lan9000Drv_Read,
		Lan9000Drv_Write,
		Lan9000Drv_Flush,
	};


/** コンストラクタ */
void Lan9000Drv_Create(C_LAN9000DRV *self, void *pRegAddr, int iIntNum)
{
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &Lan9000Drv_Methods);

	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	
	/* Lan9000Hal 初期化 */
	Lan9000Hal_Create(&self->Lan9000Hal, pRegAddr);
	
	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtSend = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtx = SysMtx_Create();

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	self->hIsr = SysIsr_Create(iIntNum, Lan9000Drv_Isr, (VPARAM)self);
}


/* end of file */

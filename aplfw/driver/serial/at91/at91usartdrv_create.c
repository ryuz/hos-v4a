/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_create.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS At91UsartDrv_Methods = 
	{
		At91UsartDrv_Delete,
		At91UsartDrv_Open,
		At91UsartDrv_Close,
		At91UsartDrv_IoControl,
		At91UsartDrv_Seek,
		At91UsartDrv_Read,
		At91UsartDrv_Write,
		At91UsartDrv_Flush,
	};


/** コンストラクタ */
void At91UsartDrv_Create(C_AT91USARTDRV *self, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &At91UsartDrv_Methods);

	/* メンバ変数初期化 */
	self->pRegBase    = pRegBase;
	self->ulBaseClock = ulBaseClock;
	self->iIntNum     = iIntNum;
	self->iOpenCount  = 0;

	/* バッファ確保 */
	pMem = SysMem_Alloc(iBufSize);
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtSend = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create();
	self->hMtxRecv = SysMtx_Create();

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	SysIsr_Create(iIntNum, At91UsartDrv_Isr, (VPARAM)self);
}


/* end of file */

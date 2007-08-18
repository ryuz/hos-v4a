/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_create.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS At91UartDrv_Methods = 
	{
		At91UartDrv_Delete,
		At91UartDrv_Open,
		At91UartDrv_Close,
		At91UartDrv_IoControl,
		At91UartDrv_Seek,
		At91UartDrv_Read,
		At91UartDrv_Write,
		At91UartDrv_Flush,
	};


/** コンストラクタ */
void At91UartDrv_Create(C_AT91UARTDRV *self, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &At91UartDrv_Methods);

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
	SysIsr_Create(iIntNum, At91UartDrv_Isr, (VPARAM)self);
}


/* end of file */

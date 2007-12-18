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


/** コンストラクタ */
void At91UsartDrv_Constructor(C_AT91USARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	SyncDrv_Constructor(&self->SyncDrv, pMethods);
	
	/* メンバ変数初期化 */
	self->pRegBase    = pRegBase;
	self->ulBaseClock = ulBaseClock;
	self->iIntNum     = iIntNum;
	self->iOpenCount  = 0;

	/* バッファ確保 */
	pMem = SysMem_Alloc(iBufSize);
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);
	self->hEvtSend = SysEvt_Create(SYSEVT_ATTR_AUTOCLEAR);

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->hMtxRecv = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	SysIsr_Create(iIntNum, At91UsartDrv_Isr, (VPARAM)self);
}


/* end of file */

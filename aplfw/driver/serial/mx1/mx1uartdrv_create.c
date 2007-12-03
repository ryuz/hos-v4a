/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_create.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Mx1UartDrv_Methods = 
	{
		Mx1UartDrv_Delete,
		Mx1UartDrv_Open,
		Mx1UartDrv_Close,
		Mx1UartDrv_IoControl,
		Mx1UartDrv_Seek,
		Mx1UartDrv_Read,
		Mx1UartDrv_Write,
		Mx1UartDrv_Flush,
	};


/** コンストラクタ */
void Mx1UartDrv_Create(C_MX1UARTDRV *self, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &Mx1UartDrv_Methods);

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
	SysIsr_Create(iIntNum + 4, Mx1UartDrv_IsrTx, (VPARAM)self);
	SysIsr_Create(iIntNum + 5, Mx1UartDrv_IsrRx, (VPARAM)self);
}


/* end of file */

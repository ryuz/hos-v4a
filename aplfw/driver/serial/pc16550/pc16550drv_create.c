/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{PC16550用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pc16550drv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS Pc16550Drv_Methods = 
	{
		Pc16550Drv_Delete,
		Pc16550Drv_Open,
		Pc16550Drv_Close,
		Pc16550Drv_IoControl,
		Pc16550Drv_Seek,
		Pc16550Drv_Read,
		Pc16550Drv_Write,
		Pc16550Drv_Flush,
	};


/** コンストラクタ */
void Pc16550Drv_Create(C_PC16550DRV *self, void *pRegAddr,  unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &Pc16550Drv_Methods);

	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	
	/* Pc16550Hal 初期化 */
	Pc16550Hal_Create(&self->Pc16550Hal, pRegAddr, uiRegStep, lSysClock);

	/* バッファ確保 */
	pMem = SysMem_Alloc(iBufSize);
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);
	
	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create(SYSMTX_ATTR_NORMAL);
	self->hMtxRecv = SysMtx_Create(SYSMTX_ATTR_NORMAL);

	/* 割込み処理登録 */
	self->iIntNum = iIntNum;
	SysIsr_Create(iIntNum, Pc16550Drv_Isr, (VPARAM)self);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{SCI用デバイスドライバ}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/* 仮想関数テーブル */
const T_DRVOBJ_METHODS SciDrv_Methods = 
	{
		SciDrv_Delete,
		SciDrv_Open,
		SciDrv_Close,
		SciDrv_IoControl,
		SciDrv_Seek,
		SciDrv_Read,
		SciDrv_Write,
		SciDrv_Flush,
	};


/** コンストラクタ */
void SciDrv_Create(C_SCIDRV *self, void *pRegAddr, int iIntNum, unsigned long ulSysClock, int iBufSize)
{
	void *pMem;
	
	/* 親クラスコンストラクタ呼び出し */
	ChrDrv_Create(&self->ChrDrv, &SciDrv_Methods);

	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	
	/* SciHal 初期化 */
	SciHal_Create(&self->SciHal, pRegAddr, ulSysClock);

	/* バッファ確保 */
	pMem = SysMem_Alloc(iBufSize);
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);

	/* イベント生成 */
	self->hEvtRecv = SysEvt_Create();
	self->hEvtSend = SysEvt_Create();

	/* ミューテックス生成 */
	self->hMtxSend = SysMtx_Create();
	self->hMtxRecv = SysMtx_Create();

	/* 割り込み処理登録 */
	SysIsr_Create(iIntNum + 0, SciDrv_IsrRecvErr, (VPARAM)self);
	SysIsr_Create(iIntNum + 1, SciDrv_IsrRecv,    (VPARAM)self);
	SysIsr_Create(iIntNum + 2, SciDrv_IsrSend,    (VPARAM)self);
	SysIsr_Create(iIntNum + 3, SciDrv_IsrSendEnd, (VPARAM)self);
}


/* end of file */

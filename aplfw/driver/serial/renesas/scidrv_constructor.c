/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** コンストラクタ */
FILE_ERR SciDrv_Constructor(C_SCIDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulSysClock, int iBufSize)
{
	FILE_ERR	ErrCode;
	void		*pMem;

	/* バッファ用メモリ確保 */
	if ( (pMem = SysMem_Alloc(iBufSize)) == NULL )
	{
		return FILE_ERR_NG;
	}
	
	/* 親クラスコンストラクタ呼び出し */
	if ( (ErrCode = SyncDrv_Constructor(&self->SyncDrv, pMethods, SYNCDRV_FACTOR_NUM)) != FILE_ERR_OK )
	{
		SysMem_Free(pMem);
		return ErrCode;
	}

	/* メンバ変数初期化 */
	self->iOpenCount = 0;
	self->iIntNum    = iIntNum;

	/* SciHal 初期化 */
	SciHal_Create(&self->SciHal, pRegBase, ulSysClock);
	
	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);

	/* 割込み処理登録 */
	self->hIsrRxErr = SysIsr_Create(iIntNum + 0, SciDrv_IsrRxErr, (VPARAM)self);
	self->hIsrRx    = SysIsr_Create(iIntNum + 1, SciDrv_IsrRx,    (VPARAM)self);
	self->hIsrTx    = SysIsr_Create(iIntNum + 2, SciDrv_IsrTx,    (VPARAM)self);
	self->hIsrTxEnd = SysIsr_Create(iIntNum + 3, SciDrv_IsrTxEnd, (VPARAM)self);
	
	return FILE_ERR_OK;
}


/* end of file */

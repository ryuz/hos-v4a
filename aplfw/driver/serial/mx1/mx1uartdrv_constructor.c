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


/** コンストラクタ */
FILE_ERR Mx1UartDrv_Constructor(C_MX1UARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
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
	self->pRegBase    = pRegBase;
	self->ulBaseClock = ulBaseClock;
	self->iIntNum     = iIntNum;
	self->iOpenCount  = 0;

	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);
	
	/* 割込み処理登録 */
	self->hIsrTx = SysIsr_Create(self->iIntNum + 4, Mx1UartDrv_IsrTx, (VPARAM)self);
	self->hIsrRx = SysIsr_Create(self->iIntNum + 5, Mx1UartDrv_IsrRx, (VPARAM)self);

	return FILE_ERR_OK;
}


/* end of file */

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



/** コンストラクタ */
FILE_ERR Pc16550Drv_Constructor(C_PC16550DRV *self, const T_FILEOBJ_METHODS *pMethods, void *pRegAddr,  unsigned int uiRegStep, int iIntNum, long lSysClock, int iBufSize)
{
	FILE_ERR	ErrCode;
	void 		*pMem;

	/* バッファ確保 */
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
	
	/* Pc16550Hal 初期化 */
	Pc16550Hal_Create(&self->Pc16550Hal, pRegAddr, uiRegStep, lSysClock);

	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);

	/* 割込みサービスルーチン生成 */
	self->iIntNum = iIntNum;
	self->hIsr = SysIsr_Create(iIntNum, Pc16550Drv_Isr, (VPARAM)self);
	
	return FILE_ERR_OK;
}


/* end of file */

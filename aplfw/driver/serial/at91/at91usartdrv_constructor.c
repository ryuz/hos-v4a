/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_constructor.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** コンストラクタ */
FILE_ERR At91UsartDrv_Constructor(C_AT91USARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
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
	self->hIsr = SysIsr_Create(self->iIntNum, At91UsartDrv_Isr, (VPARAM)self);

	return FILE_ERR_OK;
}


/* end of file */

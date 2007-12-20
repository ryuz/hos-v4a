/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_constructor.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/** コンストラクタ */
FILE_ERR Mn103ScDrv_Constructor(C_MN103SCDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize)
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
	self->iIntNumTx   = iIntNumTx;
	self->iIntNumRx   = iIntNumRx;
	self->iOpenCount  = 0;
	
	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);
	
	/* 割込み処理登録 */
	self->hIsrTx = SysIsr_Create(self->iIntNumTx, Mn103ScDrv_IsrTx, (VPARAM)self);
	self->hIsrRx = SysIsr_Create(self->iIntNumRx, Mn103ScDrv_IsrRx, (VPARAM)self);

	return FILE_ERR_OK;
}


/* end of file */

/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_constructor.c
 * @brief %jp{JellyUart オブジェクト削除}%en{JellyUart  delete object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"



/** %jp{仮想関数テーブル}%en{virtual functions table} */
const T_DRVOBJ_METHODS JellyUartDrv_Methods = 
	{
		{ JellyUartDrv_Delete },
		JellyUartDrv_Open,
		JellyUartDrv_Close,
		JellyUartDrv_IoControl,
		JellyUartDrv_Seek,
		JellyUartDrv_Read,
		JellyUartDrv_Write,
		JellyUartDrv_Flush,
	};



/** コンストラクタ */
FILE_ERR JellyUartDrv_Constructor(C_JELLYUARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNumRx, int iIntNumTx, int iBufSize)
{
	FILE_ERR	ErrCode;
	void		*pMem;
	
	/* 仮想関数テーブル */
	if ( pMethods == NULL )
	{
		pMethods = &JellyUartDrv_Methods;
	}
	
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
	self->iIntNumRx   = iIntNumRx;
	self->iIntNumTx   = iIntNumTx;
	self->iOpenCount  = 0;

	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);
	
	/* 割込み処理登録 */
	self->hIsrRx = SysIsr_Create(self->iIntNumRx, JellyUartDrv_IsrRx, (VPARAM)self);
	self->hIsrTx = SysIsr_Create(self->iIntNumTx, JellyUartDrv_IsrTx, (VPARAM)self);
	if ( self->hIsrRx == SYSISR_HANDLE_NULL || self->hIsrTx == SYSISR_HANDLE_NULL )
	{
		StreamBuf_Delete(&self->StmBufRecv);
		SysMem_Free(pMem);
		SyncDrv_Destructor(&self->SyncDrv);
		SysIsr_Delete(self->hIsrRx);
		SysIsr_Delete(self->hIsrTx);
		return FILE_ERR_NG;		
	}
	
	return FILE_ERR_OK;
}


/* end of file */

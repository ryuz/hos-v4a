/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_constructor.c
 * @brief %jp{XILINX UART driver オブジェクト削除}%en{XILINX UART driver  delete object}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"



/** %jp{仮想関数テーブル}%en{virtual functions table} */
const T_DRVOBJ_METHODS XilinxUartDrv_Methods = 
	{
		{ XilinxUartDrv_Delete },
		XilinxUartDrv_Open,
		XilinxUartDrv_Close,
		XilinxUartDrv_IoControl,
		XilinxUartDrv_Seek,
		XilinxUartDrv_Read,
		XilinxUartDrv_Write,
		XilinxUartDrv_Flush,
	};



/** コンストラクタ */
FILE_ERR XilinxUartDrv_Constructor(C_XILINXUARTDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, int iBufSize)
{
	FILE_ERR	ErrCode;
	void		*pMem;
	
	/* 仮想関数テーブル */
	if ( pMethods == NULL )
	{
		pMethods = &XilinxUartDrv_Methods;
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
	self->iIntNum     = iIntNum;
	self->iOpenCount  = 0;

	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);
	
	/* 割込み処理登録 */
	self->hIsr = SysIsr_Create(self->iIntNum, XilinxUartDrv_Isr, (VPARAM)self);
	if ( self->hIsr == SYSISR_HANDLE_NULL )
	{
		StreamBuf_Delete(&self->StmBufRecv);
		SysMem_Free(pMem);
		SyncDrv_Destructor(&self->SyncDrv);
		return FILE_ERR_NG;		
	}
	
	return FILE_ERR_OK;
}


/* end of file */

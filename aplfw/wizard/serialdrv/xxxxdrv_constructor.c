/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_constructor.c
 * @brief %jp{$OBJNAME_JP$ オブジェクト削除}%en{$OBJNAME_EN$  delete object}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"



/** %jp{仮想関数テーブル}%en{virtual functions table} */
const T_DRVOBJ_METHODS XxxxDrv_Methods = 
	{
		{ XxxxDrv_Delete },
		XxxxDrv_Open,
		XxxxDrv_Close,
		XxxxDrv_IoControl,
		XxxxDrv_Seek,
		XxxxDrv_Read,
		XxxxDrv_Write,
		XxxxDrv_Flush,
	};



/** コンストラクタ */
FILE_ERR XxxxDrv_Constructor(C_XXXXDRV *self, const T_DRVOBJ_METHODS *pMethods, void *pRegBase, int iIntNum, unsigned long ulBaseClock, int iBufSize)
{
	FILE_ERR	ErrCode;
	void		*pMem;
	
	/* 仮想関数テーブル */
	if ( pMethods == NULL )
	{
		pMethods = &XxxxDrv_Methods;
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
	self->ulBaseClock = ulBaseClock;
	self->iIntNum     = iIntNum;
	self->iOpenCount  = 0;

	/* バッファ生成 */
	StreamBuf_Create(&self->StmBufRecv, iBufSize, pMem);
	
	/* 割込み処理登録 */
	self->hIsr = SysIsr_Create(self->iIntNum, XxxxDrv_Isr, (VPARAM)self);
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

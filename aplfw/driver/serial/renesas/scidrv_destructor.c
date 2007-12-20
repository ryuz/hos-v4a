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


/** デストラクタ */
void SciDrv_Destructor(C_SCIDRV *self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsrRxErr);
	SysIsr_Delete(self->hIsrRx);
	SysIsr_Delete(self->hIsrTx);
	SysIsr_Delete(self->hIsrTxEnd);
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */

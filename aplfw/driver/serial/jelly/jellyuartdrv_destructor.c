/** 
 * Hyper Operating System  Application Framework
 *
 * @file  jellyuartdrv_destructor.c
 * @brief %jp{JellyUart デストラクタ}%en{JellyUart  destructor}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyuartdrv_local.h"


/** デストラクタ */
void JellyUartDrv_Destructor(C_JELLYUARTDRV *self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsrRx);
	SysIsr_Delete(self->hIsrTx);
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */

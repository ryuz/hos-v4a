/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_destructor.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/** デストラクタ */
void Mn103ScDrv_Destructor(C_MN103SCDRV *self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsrTx);
	SysIsr_Delete(self->hIsrRx);
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */

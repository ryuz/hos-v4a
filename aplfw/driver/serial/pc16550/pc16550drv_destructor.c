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


/** デストラクタ */
void Pc16550Drv_Destructor(C_PC16550DRV	*self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsr);
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ呼び出し */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */

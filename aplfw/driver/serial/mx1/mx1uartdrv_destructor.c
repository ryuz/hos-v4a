/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mx1uartdrv_delete.c
 * @brief %jp{Freescale MX1 UART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mx1uartdrv_local.h"


/** デストラクタ */
void Mx1UartDrv_Destructor(C_MX1UARTDRV *self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsrTx);
	SysIsr_Delete(self->hIsrRx);

	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ呼び出し */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */

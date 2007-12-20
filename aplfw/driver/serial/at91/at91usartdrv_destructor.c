/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_destructor.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** デストラクタ */
void At91UsartDrv_Destructor(C_AT91USARTDRV *self)
{
	void	*pMem;

	/* 割込みサービスルーチン削除 */
	SysIsr_Delete(self->hIsr);
	
	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
	
	/* 親クラスデストラクタ */
	SyncDrv_Destructor(&self->SyncDrv);
}


/* end of file */

/** 
 * Hyper Operating System  Application Framework
 *
 * @file  xilinxuartdrv_destructor.c
 * @brief %jp{XILINX UART driver デストラクタ}%en{XILINX UART driver  destructor}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "xilinxuartdrv_local.h"


/** デストラクタ */
void XilinxUartDrv_Destructor(C_XILINXUARTDRV *self)
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

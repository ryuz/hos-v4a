/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91uartdrv_delete.c
 * @brief %jp{ATMEL AT91シリーズUART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91uartdrv_local.h"


/** デストラクタ */
void At91UartDrv_Delete(C_DRVOBJ *pDrvObj)
{
	C_AT91UARTDRV	*self;
	void			*pMem;
	
	/* upper cast */
	self = (C_AT91UARTDRV *)pDrvObj;

	/* 同期オブジェクト削除 */
	SysEvt_Delete(self->hEvtRecv);
	SysEvt_Delete(self->hEvtSend);
	SysMtx_Delete(self->hMtxRecv);
	SysMtx_Delete(self->hMtxSend);

	/* バッファ削除 */
	pMem = StreamBuf_RefBufAddr(&self->StmBufRecv);
	StreamBuf_Delete(&self->StmBuf);
	SysMem_Free(pMem);
}


/* end of file */

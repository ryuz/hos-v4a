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
void Mx1UartDrv_Delete(C_DRVOBJ *pDrvObj)
{
	C_MX1UARTDRV	*self;
	void			*pMem;
	
	/* upper cast */
	self = (C_MX1UARTDRV *)pDrvObj;

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

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
void Pc16550Drv_Delete(C_DRVOBJ *pDrvObj)
{
	C_PC16550DRV	*self;
	void			*pMem;
	
	/* upper cast */
	self = (C_PC16550DRV *)pDrvObj;

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

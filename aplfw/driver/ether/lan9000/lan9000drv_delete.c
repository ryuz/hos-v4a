/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9000drv.h
 * @brief %jp{LAN9000ファミリー用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9000drv_local.h"


/** デストラクタ */
void Lan9000Drv_Delete(C_DRVOBJ *pDrvObj)
{
	C_LAN9000DRV	*self;
	
	/* upper cast */
	self = (C_LAN9000DRV *)pDrvObj;

	/* 割込み処理解除 */
	SysIsr_Delete(self->hIsr);

	/* 同期オブジェクト削除 */
	SysEvt_Delete(self->hEvtRecv);
	SysEvt_Delete(self->hEvtSend);
	SysMtx_Delete(self->hMtx);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_delete.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


/** デストラクタ */
void Lan9118Drv_Delete(C_DRVOBJ *pDrvObj)
{
	C_LAN9118DRV	*self;
	
	/* upper cast */
	self = (C_LAN9118DRV *)pDrvObj;

	/* 同期オブジェクト削除 */
	SysEvt_Delete(self->hEvtRecv);
	SysEvt_Delete(self->hEvtSend);
	SysMtx_Delete(self->hMtxRecv);
	SysMtx_Delete(self->hMtxSend);
}


/* end of file */

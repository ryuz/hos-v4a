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
void Lan9000Drv_Destructor(C_LAN9000DRV *self)
{
	/* 割込み処理解除 */
	SysIsr_Delete(self->hIsr);

	/* 同期オブジェクト削除 */
	SysMtx_Delete(self->hMtx);
}


/* end of file */

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
void Lan9000Drv_Delete(HANDLE hDriver)
{
	C_LAN9000DRV	*self;
	
	/* upper cast */
	self = (C_LAN9000DRV *)hDriver;

	/* デストラクタ呼び出し */
	Lan9000Drv_Destructor(self);

	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */

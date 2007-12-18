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
void Pc16550Drv_Delete(HANDLE hDriver)
{
	C_PC16550DRV	*self;
	
	/* upper cast */
	self = (C_PC16550DRV *)hDriver;
	
	/* デストラクタ呼び出し */
	Pc16550Drv_Destructor(self);

	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */

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
void Mx1UartDrv_Delete(HANDLE hDriver)
{
	C_MX1UARTDRV	*self;
	
	/* upper cast */
	self = (C_MX1UARTDRV *)hDriver;
	
	/* デストラクタ呼び出し */
	Mx1UartDrv_Destructor(self);

	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */

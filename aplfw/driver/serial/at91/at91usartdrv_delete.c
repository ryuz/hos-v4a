/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_delete.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


/** 削除 */
void At91UsartDrv_Delete(HANDLE hDriver)
{
	C_AT91USARTDRV	*self;
	
	/* upper cast */
	self = (C_AT91USARTDRV *)hDriver;

	/* デストラクタ呼び出し */
	At91UsartDrv_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */

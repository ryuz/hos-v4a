/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_delete.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


/** 削除 */
void JellyI2cDrv_Delete(HANDLE hDriver)
{
	C_JELLYI2CDRV	*self;
	
	/* upper cast */
	self = (C_JELLYI2CDRV *)hDriver;

	/* デストラクタ呼び出し */
	JellyI2cDrv_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */

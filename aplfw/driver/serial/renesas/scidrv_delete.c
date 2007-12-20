/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


/** 削除 */
void SciDrv_Delete(HANDLE hDriver)
{
	C_SCIDRV	*self;
	
	/* upper cast */
	self = (C_SCIDRV *)hDriver;

	/* デストラクタ呼び出し */
	SciDrv_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_delete.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


/** 削除 */
void Mn103ScDrv_Delete(HANDLE hDriver)
{
	C_MN103SCDRV	*self;
	
	/* upper cast */
	self = (C_MN103SCDRV *)hDriver;

	/* デストラクタ呼び出し */
	Mn103ScDrv_Destructor(self);
	
	/* メモリ削除 */
	SysMem_Free(self);
}


/* end of file */

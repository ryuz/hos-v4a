/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncfile.h
 * @brief %jp{同期機能付きデバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "syncdrv_local.h"


void SyncDrv_Delete(HANDLE hDriver)
{
	C_SYNCDRV *self;

	self = (C_SYNCDRV *)hDriver;
	
	/* デストラクタ呼び出し */
	DrvObj_Destructor(&self->DrvObj);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */

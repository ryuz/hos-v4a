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


void SyncDrv_Destructor(C_SYNCDRV *self)
{
	/* 排他制御ミューテックス削除 */
	SysMtx_Delete(self->hMtx);
	
	/* 親クラスデストラクタ呼び出し */
	FileObj_Destructor(&self->FileObj);
}


/* end of file */

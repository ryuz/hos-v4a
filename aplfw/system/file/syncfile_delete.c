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



#include "syncfile_local.h"
#include "syncdrv.h"


void SyncFile_Delete(HANDLE hFile)
{
	C_SYNCFILE *self;
	
	self = (C_SYNCFILE *)hFile;
	
	/* デストラクタ呼び出し */
	SyncFile_Destructor(self);
	
	/* メモリ開放 */
	SysMem_Free(self);
}


/* end of file */

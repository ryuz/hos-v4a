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


static const T_FILEOBJ_METHODS SyncFile_FileObjMethods =
	{
		{File_Close},
	};


HANDLE SyncFile_Create(struct c_syncdrv *pSyncDrv, int iMode)
{
	C_SYNCFILE *self;
	
	/* メモリ確保 */
	if ( (self = (C_SYNCFILE *)SysMem_Alloc(sizeof(C_SYNCFILE))) == NULL )
	{
		return HANDLE_NULL;
	}
	
	/* コンストラクタ呼び出し */
	if ( SyncFile_Constructor(self, &SyncFile_FileObjMethods, pSyncDrv, iMode) != FILE_ERR_OK )
	{
		SysMem_Free(self);
		return HANDLE_NULL;
	}
	
	return (HANDLE)self;
}


/* end of file */

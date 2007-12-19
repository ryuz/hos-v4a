/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  syncfile.h
 * @brief %jp{同期機能付きデバイスドライバ基本クラス}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "hosaplfw.h"
#include "syncdrv_local.h"
#include "system/system/system.h"


/** 処理の開始 */
FILE_ERR SyncDrv_StartProcess(C_SYNCDRV *self, C_SYNCFILE *pSyncFile, int iFuctor)
{
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* シグナルをクリア */
	SyncFile_ClearSignal(pSyncFile, iFuctor);
	
	if ( self->ppBusyFile[iFuctor] == NULL )
	{
		/* 誰も処理していなければ処理開始 */
		self->ppBusyFile[iFuctor] = pSyncFile;
	}
	else
	{
		/* ブロッキングモードで無いなら抜ける */
		if ( SyncFile_GetSyncMode(pSyncFile, iFuctor) != FILE_SYNCMODE_BLOCKING )
		{
			SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
			return FILE_ERR_BUSY;
		}
		
		/* 空くまで待つ */
		SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
		for ( ; ; )
		{
			/* シグナルを待つ */
			SyncFile_WaitSignal(pSyncFile, iFuctor);

			SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
			if ( self->ppBusyFile[iFuctor] == NULL )
			{
				/* 誰も処理していなければ処理開始 */
				self->ppBusyFile[iFuctor] = pSyncFile;
				break;
			}
			SyncFile_ClearSignal(pSyncFile, iFuctor);
			SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */		
		}
	}
	
	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
	
	return FILE_ERR_OK;
}


/* end of file */

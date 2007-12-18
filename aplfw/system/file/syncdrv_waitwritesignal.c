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


/** 書込み可能になった可能性があるまで待つ */
FILE_ERR SyncDrv_WaitWriteSignal(C_SYNCDRV *self, C_SYNCFILE *pFile)
{
	SYSPRC_HANDLE	hPrc;

	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* ファイルモードチェック */
	if ( (pFile->cWriteMode & FILE_WMODE_POLING) || pFile->hPrcWrite != SYSPRC_HANDLE_NULL )
	{
		SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
		return FILE_ERR_NG;			/* ポーリングモードならブロックしない */
	}

	/* 状態チェック */
	if ( self->iStatus & SYNCDRV_STATUS_WRITE )
	{
		SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
		return FILE_ERR_OK;			/* 即時成功 */
	}

	/* 自プロセス取得 */
	hPrc = SysPrc_GetCurrentHandle();
	
	/* 待ちタスク登録 */
	pFile->hPrcWrite = hPrc;
	
	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
	
	/* 待ちに入る */
	SysPrc_Suspend(hPrc);
	
	return FILE_ERR_OK;
}



/* end of file */

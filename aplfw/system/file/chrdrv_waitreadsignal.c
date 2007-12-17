/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  chrfile.h
 * @brief %jp{キャラクタ型デバイスドライバ用ファイルディスクリプタ}
 *
 * %jp{ファイルディスクリプタとして機能するクラス}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "chrdrv_local.h"


/** 読み可能になった可能性があるまで待つ */
FILE_ERR ChrDrv_WaitReadSignal(C_CHRDRV *self, C_CHRFILE *pFile)
{
	SYSPRC_HANDLE	hPrc;
	
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* ファイルモードチェック */
	if ( (pFile->cReadMode & FILE_RMODE_POLING) || pFile->hPrcRead != SYSPRC_HANDLE_NULL )
	{
		SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
		return FILE_ERR_NG;			/* ポーリングモードならブロックしない */
	}

	/* 状態チェック */
	if ( self->iStatus & CHRDRV_STATUS_READ )
	{
		SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
		return FILE_ERR_OK;			/* 即時成功 */
	}
	
	/* 自プロセス取得 */
	hPrc = SysPrc_GetCurrentHandle();
	
	/* 待ちタスク登録 */
	pFile->hPrcRead = hPrc;
	
	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
	
	/* 待ちに入る */
	SysPrc_Suspend(hPrc);
	
	return FILE_ERR_OK;
}


/* end of file */

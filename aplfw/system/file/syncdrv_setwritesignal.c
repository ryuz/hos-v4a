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



#include "hosaplfw.h"
#include "syncdrv_local.h"
#include "system/system/system.h"


static void SyncDrv_SetWriteSignalProc(VPARAM Param);


/** 書込み可能になったことを通知 */
void SyncDrv_SetWriteSignal(C_SYNCDRV *self)
{
	if ( SysCtx_IsIsr() )
	{
		/* ISRからの呼び出しなら、システムプロセス経由で発動 */
		System_RequestProc(SyncDrv_SetWriteSignalProc, (VPARAM)self);	
	}
	else
	{
		/* そうでなければ直接実行 */
		SyncDrv_SetWriteSignalProc((VPARAM)self);
	}
}


/** 書込み可能になったことを通知 */
void SyncDrv_SetWriteSignalProc(VPARAM Param)
{
	C_SYNCDRV	*self;
	C_SYNCFILE	*pFile;
	
	self = (C_SYNCDRV *)Param;
	
	
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	
	/* 書き込み状態設定 */
	self->iStatus |= SYNCDRV_STATUS_WRITE;
	
	/* 待ちオブジェクトにシグナルを送る */
	pFile = self->pFileHead;
	if ( pFile != NULL )
	{
		do
		{
			/* イベントハンドルが登録されていたらセット */
			if ( pFile->hEventWrite != HANDLE_NULL )
			{
				Event_Set(pFile->hEventWrite);
			}
			
			/* 待ちタスクがあれば起こして登録解除 */
			if ( pFile->hPrcWrite != SYSPRC_HANDLE_NULL )
			{
				SysPrc_Resume(pFile->hPrcWrite);
				pFile->hPrcWrite = SYSPRC_HANDLE_NULL;
			}
			
			/* 次に進む */
			pFile = pFile->pNext;
		} while ( pFile != self->pFileHead);
	}
	
	
	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
}



/* end of file */

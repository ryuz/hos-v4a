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



#include "hosaplfw.h"
#include "chrdrv_local.h"
#include "system/system/system.h"


static void ChrDrv_SetWriteSignalProc(VPARAM Param);


/** 書込み可能になったことを通知 */
void ChrDrv_SetWriteSignal(C_CHRDRV *self)
{
	if ( SysCtx_IsIsr() )
	{
		/* ISRからの呼び出しなら、システムプロセス経由で発動 */
		System_RequestProc(ChrDrv_SetWriteSignalProc, (VPARAM)self);	
	}
	else
	{
		/* そうでなければ直接実行 */
		ChrDrv_SetWriteSignalProc((VPARAM)self);
	}
}


/** 書込み可能になったことを通知 */
void ChrDrv_SetWriteSignalProc(VPARAM Param)
{
	C_CHRDRV	*self;
	C_CHRFILE	*pFile;
	
	self = (C_CHRDRV *)Param;
	
	
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	
	/* 書き込み状態設定 */
	self->iStatus |= CHRDRV_STATUS_WRITE;
	
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

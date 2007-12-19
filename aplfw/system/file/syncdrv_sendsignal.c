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


static void SyncDrv_SendSignalProc(VPARAM Param1, VPARAM Param2);


/** シグナルを通知 */
void SyncDrv_SendSignal(C_SYNCDRV *self, int iFactor)
{
	if ( SysCtx_IsIsr() )
	{
		/* ISRからの呼び出しなら、システムプロセス経由で発動 */
		System_RequestProc(SyncDrv_SendSignalProc, (VPARAM)self, (VPARAM)iFactor);	
	}
	else
	{
		/* そうでなければ直接実行 */
		SyncDrv_SendSignalProc((VPARAM)self, (VPARAM)iFactor);
	}
}


/** シグナルを配信 */
void SyncDrv_SendSignalProc(VPARAM Param1, VPARAM Param2)
{
	C_SYNCDRV	*self;
	C_SYNCFILE	*pFile;
	int			iFactor;
	
	self    = (C_SYNCDRV *)Param1;
	iFactor = (int)Param2;
	
	
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* ファイルオブジェクトにシグナルを送る */
	pFile = self->pFileHead;
	if ( pFile != NULL )
	{
		do
		{
			/* シグナルを設定 */
			SyncFile_SetSignal(pFile, iFactor);
			
			/* 次に進む */
			pFile = pFile->pNext;
		} while ( pFile != self->pFileHead);
	}
	
	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
}


/* end of file */

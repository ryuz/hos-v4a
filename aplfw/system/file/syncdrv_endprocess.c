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



/** 処理の完了 */
void SyncDrv_EndProcess(C_SYNCDRV *self, int iFactor, VPARAM ErrCode)
{
	/* 処理完了ならエラーコード設定 */
	if ( self->ppBusyFile[iFactor] != NULL )
	{
		/* 処理完了とする */
		SyncFile_SetErrCode(self->ppBusyFile[iFactor], iFactor, ErrCode);
		self->ppBusyFile[iFactor] = NULL;
	}

	/* シグナルの送信 */
	SyncDrv_SendSignal(self, iFactor);
}


/* end of file */

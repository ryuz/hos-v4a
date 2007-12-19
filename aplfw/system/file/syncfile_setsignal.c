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



/** シグナルのセット */
void SyncFile_SetSignal(C_SYNCFILE *self, int iSignal)
{
	/* イベント設定 */
	SysEvt_Set(self->pSyncObj[iSignal].hEvt);
	
	/* 通知タイプに応じて通知実施 */
	switch ( self->pSyncObj[iSignal].Inf.Type )
	{
	case FILE_SYNCTYPE_EVENT:		/* イベント通知 */
		Event_Set(self->pSyncObj[iSignal].Inf.Sync.hEvent);
		break;
		
	case FILE_SYNCTYPE_CALLBACK:	/* コールバック通知 */
		self->pSyncObj[iSignal].Inf.Sync.Proc.pfncProc(self->pSyncObj[iSignal].Inf.Sync.Proc.Param, self->pSyncObj[iSignal].ErrCode);
		break;
	}
}


/* end of file */

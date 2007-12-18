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



/** 書込み可能になったことを通知 */
void SyncDrv_ClearWriteSignal(C_SYNCDRV *self)
{
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* 書き込み状態設定 */
	self->iStatus &= ~SYNCDRV_STATUS_WRITE;

	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
}



/* end of file */

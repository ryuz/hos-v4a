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



/** 書込み可能になったことを通知 */
void ChrDrv_ClearWriteSignal(C_CHRDRV *self)
{
	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* 書き込み状態設定 */
	self->iStatus &= ~CHRDRV_STATUS_WRITE;

	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
}



/* end of file */

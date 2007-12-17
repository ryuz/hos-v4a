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


/** 書込み可能状況参照 */
int ChrDrv_RefReadSignal(C_CHRDRV *self)
{
	int iResult;

	SysMtx_Lock(self->hMtx);	/* クリティカルセクションに入る */
	
	/* 状態取得 */
	iResult = (self->iStatus & CHRDRV_STATUS_READ) ? 1 : 0;
	
	SysMtx_Unlock(self->hMtx);	/* クリティカルセクションを出る */
	
	return iResult;
}



/* end of file */

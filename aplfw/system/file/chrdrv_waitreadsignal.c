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



#include "chrdrv.h"


/** 読込み可能になった可能性があるまで待つ */
FILE_ERR ChrDrv_WaitReadSignal(C_CHRDRV *self, C_CHRFILE *pFile)
{
	/* ファイルモードチェック */
	if ( pFile->cReadMode & FILE_RMODE_POLING )
	{
		return FILE_ERR_NG;		/* ポーリングモードならブロックしない */
	}
	
	SysEvt_Wait(self->hEvtRead);
	
	return FILE_ERR_OK;
}


/* end of file */

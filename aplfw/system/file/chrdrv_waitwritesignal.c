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


/** 書込み可能になった可能性があるまで待つ */
FILE_ERR ChrDrv_WaitWriteSignal(C_CHRDRV *self, C_CHRFILE *pFile)
{
	/* ファイルモードチェック */
	if ( pFile->cWriteMode & FILE_WMODE_POLING )
	{
		return FILE_ERR_NG;		/* ポーリングモードならブロックしない */
	}
	
	SysEvt_Wait(self->hEvtWrite);
	
	return FILE_ERR_OK;
}


/* end of file */

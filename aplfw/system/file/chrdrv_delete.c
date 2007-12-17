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


void ChrDrv_Delete(C_CHRDRV *self)
{
	SysMtx_Delete(self->hMtx);			/* 排他制御ミューテックス */
#if 0
	SysEvt_Delete(self->hEvtWrite);		/* 書込みイベント */
	SysEvt_Delete(self->hEvtRead);		/* 読込みイベント */
#endif
	
	/* 親クラスデストラクタ呼び出し */
	DrvObj_Delete(&self->DrvObj);
}


/* end of file */

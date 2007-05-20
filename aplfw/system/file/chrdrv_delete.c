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
	/* 親クラスデストラクタ呼び出し */
	DrvObj_Delete(&self->DrvObj);
}


/* end of file */

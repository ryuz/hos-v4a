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


void ChrDrv_Create(C_CHRDRV *self, const T_DRVOBJ_METHODS *pMethods)
{
	/* 親クラスコンストラクタ呼び出し */
	DrvObj_Create(&self->DrvObj, pMethods);
}


/* end of file */

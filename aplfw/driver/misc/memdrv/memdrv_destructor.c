/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "memdrv_local.h"


/** デストラクタ */
void MemDrv_Destructor(C_MEMDRV *self)
{
	/* オブジェクト削除 */
	SysMtx_Delete(self->hMtx);
	
	/* 親クラスデストラクタ */
	DrvObj_Destructor(&self->DrvObj);
}


/* end of file */

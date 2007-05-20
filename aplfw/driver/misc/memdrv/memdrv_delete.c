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
#include "system/sysapi/sysapi.h"


/** デストラクタ */
void MemDrv_Delete(C_DRVOBJ *pDrvObj)
{
	C_MEMDRV *self;
	
	/* upper cast */
	self = (C_MEMDRV *)pDrvObj;

	/* オブジェクト削除 */
	SysMtx_Delete(self->hMtx);
}


/* end of file */

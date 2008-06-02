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


/** クローズ */
void MemDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_MEMDRV	*self;
	C_MEMFILE	*pFile;
	
	/* upper cast */
	self  = (C_MEMDRV *)pDrvObj;
	pFile = (C_MEMFILE *)pFileObj;

	SysMtx_Lock(self->hMtx);
	
	/* クローズ処理 */
	--self->iOpenCount;
	
	/* ディスクリプタ削除 */
	FileObj_Delete((C_FILEOBJ *)pFile);	
	SysMem_Free(pFile);

	SysMtx_Unlock(self->hMtx);
}


/* end of file */

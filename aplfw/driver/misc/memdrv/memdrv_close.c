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
void MemDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_MEMDRV	*self;
	C_MEMFILE	*pFile;
	
	/* upper cast */
	self  = (C_MEMDRV *)pFileObj;
	pFile = (C_MEMFILE *)pFilePtr;

	SysMtx_Lock(self->hMtx);
	
	/* クローズ処理 */
	--self->iOpenCount;
	
	/* ディスクリプタ削除 */
	FilePtr_Delete((C_FILEPTR *)pFile);	
	SysMem_Free(pFile);

	SysMtx_Unlock(self->hMtx);
}


/* end of file */

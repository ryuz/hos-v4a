/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memdrv.h
 * @brief %jp{メモリマップドファイル用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include "memdrv_local.h"



FILE_SIZE MemDrv_Read(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, void *pBuf, FILE_SIZE Size)
{
	C_MEMDRV	*self;
	C_MEMFILE	*pFile;
	
	/* upper cast */
	self  = (C_MEMDRV *)pFileObj;
	pFile = (C_MEMFILE *)pFilePtr;
	
	SysMtx_Lock(self->hMtx);
	
	/* サイズクリップ */
	if ( Size > self->FileSize - pFile->FilePos )
	{
		Size = self->FileSize - pFile->FilePos;
	}
	
	/* 読み出し */
	memcpy(pBuf, self->pubMemAddr + pFile->FilePos, Size);
	pFile->FilePos += Size;
	
	SysMtx_Unlock(self->hMtx);
	
	return Size;
}


/* end of file */

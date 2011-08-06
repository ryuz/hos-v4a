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
#include "memfile_local.h"


FILE_SIZE MemDrv_Write(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, const void *pData, FILE_SIZE Size)
{
	C_MEMDRV	*self;
	C_MEMFILE	*pFile;
	
	/* upper cast */
	self  = (C_MEMDRV *)pFileObj;
	pFile = (C_MEMFILE *)pFilePtr;

	
	SysMtx_Lock(self->hMtx);
	
	/* サイズクリップ */
	if ( Size > self->MemSize - pFile->FilePos )
	{
		Size = self->MemSize - pFile->FilePos;
	}
	
	/* 書込み */
	memcpy(self->pubMemAddr + pFile->FilePos, pData, Size);
	pFile->FilePos += Size;
	
	/* ファイルサイズ拡張 */
	if ( self->FileSize < pFile->FilePos )
	{
		self->FileSize = pFile->FilePos;
	}
	
	SysMtx_Unlock(self->hMtx);
	
	return Size;
}


/* end of file */

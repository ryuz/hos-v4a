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


FILE_POS MemDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	C_MEMDRV	*self;
	C_MEMFILE	*pFile;
	
	/* upper cast */
	self  = (C_MEMDRV *)pDrvObj;
	pFile = (C_MEMFILE *)pFileObj;
	
	/* シーク */
	switch ( iOrign )
	{
	case FILE_SEEK_SET:
		pFile->FilePos  = Offset;
		break;
		
	case FILE_SEEK_CUR:
		pFile->FilePos += Offset;
		break;
		
	case FILE_SEEK_END:
		pFile->FilePos = self ->FileSize + Offset;
		break;
		
	default:
		return FILE_ERR_NG;
	}
	
	/* 範囲クリップ */
	if ( pFile->FilePos < 0 )
	{
		pFile->FilePos = 0;
	}
	if ( pFile->FilePos > self->FileSize )
	{
		pFile->FilePos = self->FileSize;
	}

	return pFile->FilePos;
}


/* end of file */

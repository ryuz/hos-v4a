/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "fatvol_local.h"


FILE_POS FatVol_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	C_FATVOL	*self;
	C_FATFILE	*pFile;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;
	
	
	/* ファイルポインタ移動 */
	switch ( iOrign )
	{
	case FILE_SEEK_SET:
		pFile->FilePos = Offset;
		break;

	case FILE_SEEK_CUR:
		pFile->FilePos += Offset;
		break;

	case FILE_SEEK_END:
		if ( Offset <= pFile->FileSize )
		{
			pFile->FilePos = pFile->FileSize + Offset;
		}
		else
		{
			pFile->FilePos = 0;
		}
		break;
	
	default:
		return FILE_ERR_NG;
	}
	
	/* サイズクリップ */
	if ( pFile->FilePos > pFile->FileSize && !(pFile->FileObj.iMode & FILE_OPEN_DIR) )
	{
		pFile->FilePos = pFile->FileSize;
	}
	
	
	return pFile->FilePos;
}


/* end of file */

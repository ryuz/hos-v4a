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


/** %jp{書き込み} */
FILE_SIZE FatVol_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_FATVOL	*self;
	C_FATFILE	*pFile;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;
	
	/* モードチェック */
	if ( !(pFile->iMode & FILE_OPEN_WRITE) )
	{
		return 0;
	}
	
	
	
	
	return 0;
}


/* end of file */

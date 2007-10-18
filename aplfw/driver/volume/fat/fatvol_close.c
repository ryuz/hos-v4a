/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  fatvol.c
 * @brief %jp{FATボリューム用デバイスドライバ}
 *
 * Copyright (C) 2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "fatvol_local.h"


/** クローズ */
void FatVol_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_FATVOL	*self;
	C_FATFILE	*pFile;
	
	/* upper cast */
	self  = (C_FATVOL *)pDrvObj;
	pFile = (C_FATFILE *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
	}
	
	/* ディスクリプタ削除 */
	SysMem_Free(pFile);
}


/* end of file */

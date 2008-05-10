/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_close.c
 * @brief %jp{PC/AT text mode driver クローズ}%en{PC/AT text mode driver  close}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


/** クローズ */
void PcatTextDrv_Close(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_PCATTEXTDRV	*self;
	C_FILEOBJ	*pFile;
	
	/* upper cast */
	self  = (C_PCATTEXTDRV *)pDrvObj;
	pFile = (C_FILEOBJ *)pFileObj;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		/* クローズ処理 */
	}
	
	/* ディスクリプタ削除 */
	FileObj_Delete((HANDLE)pFile);	
}


/* end of file */

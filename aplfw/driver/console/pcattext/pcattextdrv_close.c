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
void PcatTextDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_PCATTEXTDRV	*self;
	C_FILEPTR	*pFile;
	
	/* upper cast */
	self  = (C_PCATTEXTDRV *)pFileObj;
	pFile = (C_FILEPTR *)pFilePtr;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		/* クローズ処理 */
	}
	
	/* ディスクリプタ削除 */
	FilePtr_Delete((HANDLE)pFile);	
}


/* end of file */

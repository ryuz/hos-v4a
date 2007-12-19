/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  streampipe.c
 * @brief %jp{ストリームパイプ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "streampipe_local.h"


/** オープン */
HANDLE StreamPipe_Open(C_DRVOBJ *pDrvObj, const char *pszPath, int iMode)
{
	C_STREAMPIPE	*self;
	HANDLE			hFile;
	
	/* upper cast */
	self = (C_STREAMPIPE *)pDrvObj;

	/* create file descriptor */
	if ( (hFile = SyncFile_Create(&self->SyncDrv)) == HANDLE_NULL )
	{
		return HANDLE_NULL;
	}
	
	/* オープン処理 */
	if ( self->iOpenCount++ == 0 )
	{
		StreamBuf_Clear(&self->StreamBuf);
	}
	
	return hFile;
}


/* end of file */

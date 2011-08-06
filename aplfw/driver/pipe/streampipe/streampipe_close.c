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


/** クローズ */
void StreamPipe_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_STREAMPIPE	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_STREAMPIPE *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	/* クローズ処理 */
	if ( --self->iOpenCount == 0 )
	{
		StreamBuf_Clear(&self->StreamBuf);
	}
	
	/* ディスクリプタ削除 */
	SyncFile_Delete(pFile);	
}


/* end of file */

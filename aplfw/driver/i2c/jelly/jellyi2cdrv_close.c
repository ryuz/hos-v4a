/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  jellyi2cdrv_close.c
 * @brief %jp{Jelly I2Cデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "jellyi2cdrv_local.h"


/** クローズ */
void JellyI2cDrv_Close(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_JELLYI2CDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_JELLYI2CDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	/* クローズ処理 */
	--self->iOpenCount;
	
	/* ディスクリプタ削除 */
	SyncFile_Delete((HANDLE)pFile);	
}


/* end of file */

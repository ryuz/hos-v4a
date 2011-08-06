/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scidrv.c
 * @brief %jp{Renesas H8/SH用 SCIデバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "scidrv_local.h"


FILE_ERR SciDrv_Flush(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr)
{
	C_SCIDRV	*self;
	C_SYNCFILE	*pFile;
	
	/* upper cast */
	self  = (C_SCIDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;

	return FILE_ERR_OK;
}


/* end of file */

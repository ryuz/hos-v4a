/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  mn103scdrv_seek.c
 * @brief %jp{MN103シリーズ シリアルインターフェース用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "mn103scdrv_local.h"


FILE_POS Mn103ScDrv_Seek(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, FILE_POS Offset, int iOrign)
{
	C_MN103SCDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_MN103SCDRV *)pFileObj;
	pFile = (C_SYNCFILE *)pFilePtr;


	return FILE_ERR_NG;
}


/* end of file */

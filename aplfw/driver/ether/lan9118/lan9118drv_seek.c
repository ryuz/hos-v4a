/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  lan9118drv_seek.c
 * @brief %jp{SMSC LAN9118シリーズ用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "lan9118drv_local.h"


FILE_POS Lan9118Drv_Seek(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, FILE_POS Offset, int iOrign)
{
	C_LAN9118DRV	*self;
	C_CHRFILE		*pFile;
	
	/* upper cast */
	self  = (C_LAN9118DRV *)pFileObj;
	pFile = (C_CHRFILE *)pFilePtr;

	return FILE_ERR_NG;
}


/* end of file */

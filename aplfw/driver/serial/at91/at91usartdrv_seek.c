/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_seek.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


FILE_POS At91UsartDrv_Seek(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, FILE_POS Offset, int iOrign)
{
	C_AT91USARTDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_AT91USARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;


	return FILE_ERR_NG;
}


/* end of file */

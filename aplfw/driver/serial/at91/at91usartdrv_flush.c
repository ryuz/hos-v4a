/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  at91usartdrv_flash.c
 * @brief %jp{ATMEL AT91シリーズUSART用デバイスドライバ}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "at91usartdrv_local.h"


FILE_ERR At91UsartDrv_Flush(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj)
{
	C_AT91USARTDRV	*self;
	C_SYNCFILE		*pFile;
	
	/* upper cast */
	self  = (C_AT91USARTDRV *)pDrvObj;
	pFile = (C_SYNCFILE *)pFileObj;

	return FILE_ERR_OK;
}


/* end of file */

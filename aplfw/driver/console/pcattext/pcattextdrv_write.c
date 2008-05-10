/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_write.c
 * @brief %jp{PC/AT text mode driver 書込み}%en{PC/AT text mode driver  write}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


/** %jp{送信} */
FILE_SIZE PcatTextDrv_Write(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, const void *pData, FILE_SIZE Size)
{
	C_PCATTEXTDRV		*self;
	const unsigned char	*pubBuf;
	FILE_SIZE 			i;
	
	/* upper cast */
	self = (C_PCATTEXTDRV *)pDrvObj;
	
	pubBuf = (const unsigned char *)pData;
	
	/* 出力 */
	for ( i = 0; i < Size; i++ )
	{
		PcatTextDrv_PutChar(self, pubBuf[i]);
	}
	
	return i;
}


/* end of file */

/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_read.c
 * @brief %jp{$OBJNAME_JP$ 読込み}%en{$OBJNAME_EN$  read}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** %jp{読込み} */
FILE_SIZE XxxxDrv_Read(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, void *pBuf, FILE_SIZE Size)
{
	C_XXXXDRV	*self;
	C_FILEOBJ	*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pDrvObj;
	pFile = (C_FILEOBJ *)pFileObj;
	
	/* 読込み処理 */
	
	return 0;
}


/* end of file */

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
FILE_SIZE XxxxDrv_Read(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, void *pBuf, FILE_SIZE Size)
{
	C_XXXXDRV		*self;
	C_XXXXFILE		*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pFileObj;
	pFile = (C_XXXXFILE *)pFilePtr;

	return 0;
}


/* end of file */

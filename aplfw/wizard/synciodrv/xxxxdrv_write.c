/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_write.c
 * @brief %jp{$OBJNAME_JP$ 書込み}%en{$OBJNAME_EN$  write}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


/** %jp{送信} */
FILE_SIZE XxxxDrv_Write(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, const void *pData, FILE_SIZE Size)
{
	C_XXXXDRV			*self;
	C_XXXXFILE			*pFile;
	
	/* upper cast */
	self  = (C_XXXXDRV *)pFileObj;
	pFile = (C_XXXXFILE *)pFilePtr;
		
	return 0;
}


/* end of file */

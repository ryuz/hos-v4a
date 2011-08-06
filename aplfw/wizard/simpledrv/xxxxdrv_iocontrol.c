/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_iocontrol.c
 * @brief %jp{$OBJNAME_JP$ I/O制御}%en{$OBJNAME_EN$  I/O control}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


FILE_ERR XxxxDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return SyncDrv_IoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

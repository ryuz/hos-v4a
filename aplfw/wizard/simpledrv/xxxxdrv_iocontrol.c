/** 
 * $PROJECT_NAME$
 *
 * @file  xxxxdrv_iocontrol.c
 * @brief %jp{$OBJNAME_JP$ I/O制御}%en{$OBJNAME_EN$  I/O control}
 *
 * $COPYRIGHT$
 */


#include "xxxxdrv_local.h"


FILE_ERR XxxxDrv_IoControl(C_DRVOBJ *pDrvObj, C_FILEOBJ *pFileObj, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return SyncDrv_IoControl(pDrvObj, pFileObj, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

/** 
 * Hyper Operating System  Application Framework
 *
 * @file  pcattextdrv_iocontrol.c
 * @brief %jp{PC/AT text mode driver I/O制御}%en{PC/AT text mode driver  I/O control}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "pcattextdrv_local.h"


FILE_ERR PcatTextDrv_IoControl(C_FILEOBJ *pFileObj, C_FILEPTR *pFilePtr, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	return FileObj_IoControl(pFileObj, pFilePtr, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  drvobj.h
 * @brief %jp{デバイスドライバファイルの基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "drvfile_local.h"


/* I/O制御 */
FILE_ERR DrvFile_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	C_DRVFILE *self;

	self = DRVFILE_HANDLE2OBJ(hFile);

	return DrvObj_IoControl(self->pDrvObj, hFile, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}



/* end of file */
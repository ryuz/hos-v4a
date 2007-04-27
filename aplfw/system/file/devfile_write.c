/**
 *  Hyper Operating System  Application Framework
 *
 * @file  drvfile.h
 * @brief %jp{デバイスドライバファイルの基本クラス}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "drvfile_local.h"


/* 読込み */
FILE_SIZE DrvFile_Write(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_DRVFILE *self;

	self = DRVFILE_HANDLE2OBJ(hFile);
	
	return DrvObj_Read(self->pDrvObj, hFile, pBuf, 0, Size);
}


/* end of file */

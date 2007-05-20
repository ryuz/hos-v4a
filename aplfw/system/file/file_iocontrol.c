/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "file_local.h"
#include "fileobj.h"


FILE_ERR File_IoControl(HANDLE hFile, int iFunc, void *pInBuf, FILE_SIZE InSize, const void *pOutBuf, FILE_SIZE OutSize)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	return DrvObj_vIoControl(self->pDrvObj, self, iFunc, pInBuf, InSize, pOutBuf, OutSize);
}



/* end of file */

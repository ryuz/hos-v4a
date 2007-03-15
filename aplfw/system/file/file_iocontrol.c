/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include "file_local.h"
#include "fileobj.h"


FILE_ERR File_IoControl(HANDLE hFile, int iFunc, const void *pInBuf, FILE_SIZE InSize, void *pOutBuf, FILE_SIZE OutSize)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncIoControl != NULL )
	{
		return FileObj_GetMethods(self)->pfncIoControl(hFile, iFunc, pInBuf, InSize, pOutBuf, OutSize);
	}

	return FILE_ERR_NG;
}



/* end of file */

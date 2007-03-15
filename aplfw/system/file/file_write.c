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


FILE_SIZE File_Write(HANDLE hFile, const void *pData, FILE_SIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);

	if ( FileObj_GetMethods(self)->pfncWrite != NULL )
	{
		return FileObj_GetMethods(self)->pfncWrite(hFile, pData, Size);
	}

	return FILE_ERR_NG;
}



/* end of file */

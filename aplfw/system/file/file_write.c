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
	
	return DrvObj_vWrite(self->pDrvObj, self, pData, Size);
}



/* end of file */

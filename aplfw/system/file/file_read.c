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



FILE_SIZE File_Read(HANDLE hFile, void *pBuf, FILE_SIZE Size)
{
	C_FILEOBJ *self;

	self = FILE_HANDLE2OBJ(hFile);
	
	return DrvObj_vRead(self->pDrvObj, self, pBuf, Size);
}



/* end of file */

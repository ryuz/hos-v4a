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


void File_Close(HANDLE hFile)
{
	C_FILEOBJ *self;
	
	self = FILE_HANDLE2OBJ(hFile);
	
	DrvObj_vClose(self->pDrvObj, self);
}



/* end of file */

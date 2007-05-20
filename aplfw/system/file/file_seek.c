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


FILE_POS File_Seek(HANDLE hFile, FILE_POS Offset, int iOrign)
{
	C_FILEOBJ *self;
	
	self = FILE_HANDLE2OBJ(hFile);

	return DrvObj_vSeek(self->pDrvObj, self, Offset, iOrign);
}



/* end of file */

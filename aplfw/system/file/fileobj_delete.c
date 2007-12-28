/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "fileobj_local.h"


void FileObj_Delete(HANDLE hFile)
{
	C_FILEOBJ *self;
	
	self = (C_FILEOBJ *)hFile;

	FileObj_Destructor(self);
	
	SysMem_Free(self);
}


/* end of file */

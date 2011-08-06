/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "file_local.h"


void FilePtr_Delete(HANDLE hFile)
{
	C_FILEPTR *self;
	
	self = (C_FILEPTR *)hFile;

	FilePtr_Destructor(self);
	
	SysMem_Free(self);
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "fileobj.h"


void FileObj_Delete(HANDLE hFile)
{
	C_FILEOBJ *self;
	
	self = (C_FILEOBJ *)hFile;

	HandleObj_Delete(&self->HandleObj);
}


/* end of file */

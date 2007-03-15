/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "fileobj.h"


void FileObj_Delete(C_FILEOBJ *self)
{
	HandleObj_Delete(&self->HandleObj);
}



/* end of file */

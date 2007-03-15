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


int File_GetChar(HANDLE hFile)
{
	char c;
	if ( File_Read(hFile, &c, 1) != 1 )
	{
		return FILE_EOF;
	}
	return c;
}


/* end of file */

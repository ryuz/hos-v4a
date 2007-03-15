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


int File_PutChar(HANDLE hFile, int c)
{
	char b;
	b = (char)c;
	if ( File_Write(hFile, &b, 1) == 1 )
	{
		return b;
	}
	return FILE_EOF;
}


/* end of file */

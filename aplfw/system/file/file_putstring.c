/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  file.c
 * @brief %jp{ファイルシステム}
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <string.h>
#include <stdio.h>
#include "file_local.h"


int File_PutString(HANDLE hFile, const char *pszString)
{
	return File_Write(hFile, pszString, strlen(pszString));
}


/* end of file */

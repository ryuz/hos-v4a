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
	C_FILEPTR	*pFilePtr;
	char 		c;

	pFilePtr = (C_FILEPTR *)hFile;
	
	do
	{	
		if ( File_Read(hFile, &c, 1) != 1 )
		{
			return FILE_EOF;
		}
	} while ( c == '\r' && (FilePtr_GetMode(pFilePtr) & FILE_OPEN_TEXT) );

	
	return c;
}


/* end of file */

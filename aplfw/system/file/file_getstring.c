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


int File_GetString(HANDLE hFile, char *pszString, int iSize)
{
	int	i;
	int	c;
	
	for ( i = 0; i < iSize - 1; i++ )
	{
		c = File_GetChar(hFile);
		
		if ( c == FILE_EOF )
		{
			if ( i == 0 )
			{
				return FILE_EOF;
			}
			break;
		}
	
		pszString[i] = c;

		if ( c == '\n' )
		{
			i++;
			break;
		}
	}
	pszString[i] = '\0';
	
	return i;
}


/* end of file */

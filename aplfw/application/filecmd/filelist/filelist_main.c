/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  filelist.h
 * @brief %jp{ファイルリストコマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "filelist.h"


int FileList_Main(int argc, char *argv[])
{
	T_FILE_FILEINF	FileInf;
	HANDLE			hDir;
	char			*pPath = NULL;
	int				iFlagL = 0;
	int				i;
	
	
	/* コマンドライン解析 */	
	for ( i = 1; i < argc; i++ )
	{
		if ( argv[i][0] == '-' )
		{
			if ( strcmp(&argv[i][1], "l") == 0 )
			{
				iFlagL = 1;
			}
		}
		else
		{
			if ( pPath == NULL )
			{
				pPath = argv[i];
			}
		}
	}
	if ( pPath == NULL )
	{
		return 1;
	}

	
	/* ディレクトリを開く */	
	if ( (hDir = File_Open(pPath, FILE_OPEN_READ | FILE_OPEN_DIR)) == HANDLE_NULL )
	{
		return 0;
	}
	
	/* ディレクトリを読み出す */	
	while ( File_ReadDir(hDir, &FileInf) == FILE_ERR_OK )
	{
		if ( iFlagL )
		{
			StdIo_PrintFormat("%s %8ld\n", FileInf.szFileName, (long)FileInf.FileSize);
		}
		else
		{
			StdIo_PrintFormat("%s\n", FileInf.szFileName);
		}
	}

	/* ディレクトリを閉じる */	
	File_Close(hDir);

	return 0;
}



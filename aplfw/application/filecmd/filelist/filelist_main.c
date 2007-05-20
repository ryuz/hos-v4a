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
	
	if ( argc < 2 )
	{
		return 1;
	}
	
	/* ディレクトリを開く */	
	if ( (hDir = File_Open(argv[1], FILE_OPEN_READ | FILE_OPEN_DIR)) == HANDLE_NULL )
	{
		return 0;
	}
	
	/* ディレクトリを読み出す */	
	while ( File_ReadDir(hDir, &FileInf) == FILE_ERR_OK )
	{
		StdIo_PrintFormat("%s\n", FileInf.szFileName);
	}

	/* ディレクトリを閉じる */	
	File_Close(hDir);

	return 0;
}



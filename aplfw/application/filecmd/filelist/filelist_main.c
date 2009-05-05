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
	char			*pPath = "";
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
			pPath = argv[i];
		}
	}
	
	
	/* ディレクトリを開く */	
	if ( (hDir = File_Open(pPath, FILE_OPEN_READ | FILE_OPEN_EXIST | FILE_OPEN_DIR)) == HANDLE_NULL )
	{
		return 0;
	}

	
	if ( iFlagL )
	{
		/* 詳細表示 */
		StdIo_PutString("filename        size      attr  information\n");
		StdIo_PutString("------------+-----------+------+---------------\n");
	}
	
	/* ディレクトリを読み出す */	
	while ( File_ReadDir(hDir, &FileInf) == FILE_ERR_OK )
	{
		if ( iFlagL )
		{
			StdIo_PrintFormat("%-12s%12ld ", FileInf.szFileName, (long)FileInf.FileSize);
			if ( FileInf.Attribute & FILE_ATTR_READONLY )	{ StdIo_PutChar('r'); } else { StdIo_PutChar('-'); }
			if ( FileInf.Attribute & FILE_ATTR_SYSTEM )		{ StdIo_PutChar('s'); } else { StdIo_PutChar('-'); }
			if ( FileInf.Attribute & FILE_ATTR_HIDDEN )		{ StdIo_PutChar('h'); } else { StdIo_PutChar('-'); }
			if ( FileInf.Attribute & FILE_ATTR_DIR )		{ StdIo_PutChar('d'); } else { StdIo_PutChar('-'); }
			if ( FileInf.Attribute & FILE_ATTR_ARCHIVE )	{ StdIo_PutChar('a'); } else { StdIo_PutChar('-'); }
			StdIo_PutChar(' ');
			StdIo_PutString(FileInf.szInformation);
			StdIo_PutChar('\n');
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


/* end of file */

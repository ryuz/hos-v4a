/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  filecat_main.c
 * @brief %jp{ファイル結合コマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "filecat.h"


#define FILECAT_BUFSIZE	4096


/* ファイル結合コマンド */
int FileCat_Main(int argc, char *argv[])
{
	HANDLE		hFile;
	int			i;
	FILE_SIZE	Size;
	void		*pBuf;

	/* バッファ確保 */
	pBuf = Memory_Alloc(FILECAT_BUFSIZE);
	if ( pBuf == NULL )
	{
		return 1;
	}
	
	/* 結合 */
	for ( i = 1; i < argc; i++ )
	{
		/* Open */
		if ( (hFile = File_Open(argv[i], FILE_OPEN_READ | FILE_OPEN_EXIST)) == HANDLE_NULL )
		{
			continue;
		}
		
		/* 読み出し */
		while ( (Size = File_Read(hFile, pBuf, FILECAT_BUFSIZE)) > 0 )
		{
			StdIo_Write(pBuf, Size);
		}
		
		/* Close */
		File_Close(hFile);		
	}

	/* バッファ開放 */
	Memory_Free(pBuf);


	return 0;
}


/* end of file */

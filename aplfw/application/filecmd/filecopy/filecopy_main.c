/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  filecopy_main.c
 * @brief %jp{ファイルコピーコマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "filecopy.h"


#define FILECOPY_BUFSIZE	(32 * 1024)


int FileCopy_Main(int argc, char *argv[])
{
	HANDLE		hFileSrc;
	HANDLE		hFileDst;
	void		*pBuf;
	FILE_SIZE	Size;
	
	/* 引数チェック */
	if ( argc < 3 )
	{
		return 1;
	}
	
	/* バッファ確保 */
	pBuf = Memory_Alloc(FILECOPY_BUFSIZE);
	if ( pBuf == NULL )
	{
		return 1;
	}
	
	/* Open */
	if ( (hFileSrc = File_Open(argv[1], FILE_OPEN_READ | FILE_OPEN_EXIST)) == HANDLE_NULL )
	{
		return 1;
	}
	
	if ( (hFileDst = File_Open(argv[2], FILE_OPEN_WRITE | FILE_OPEN_CREATE)) == HANDLE_NULL )
	{
		File_Close(hFileSrc);
		return 1;
	}
	
	/* コピー */
	while ( (Size = File_Read(hFileSrc, pBuf, FILECOPY_BUFSIZE)) > 0 )
	{
		File_Write(hFileDst, pBuf, Size);
	}
	
	/* Close */
	File_Close(hFileSrc);
	File_Close(hFileDst);

	/* バッファ開放 */
	Memory_Free(pBuf);

	return 0;
}


/* end of file */

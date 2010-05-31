/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  filedump_main.c
 * @brief %jp{ファイルダンプコマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "filedump.h"

#define FILEDUMP_BUFSIZE	4096


int FileDump_Main(int argc, char *argv[])
{
	HANDLE			hFile;
	unsigned char	*pubBuf;
	unsigned long	ulSize = 0x7fffffff;
	unsigned long	ulPos  = 0;
	int				iReadSize;
	int				i;

	/* 引数チェック */
	if ( argc < 2 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s filename [size] [offest]\n\n",
				argv[0]
			);
		return 1;
	}

	/* コマンドライン解析 */
	if ( argc >= 3 )
	{
		ulSize = (int)strtoul(argv[2], 0, 0);
	}
	if ( argc >= 4 )
	{
		ulPos = (int)strtoul(argv[3], 0, 0);
	}

	
	/* ファイルをを開く */	
	if ( (hFile = File_Open(argv[1], FILE_OPEN_READ)) == HANDLE_NULL )
	{
		return 1;
	}
	ulPos = (unsigned long)File_Seek(hFile, ulPos, FILE_SEEK_SET);
		
	/* バッファ確保 */
	pubBuf = (unsigned char *)Memory_Alloc(FILEDUMP_BUFSIZE);
	if ( pubBuf == NULL )
	{
		File_Close(hFile);
		return 1;
	}
	
	
	while ( ulSize > 0 )
	{
		if ( ulSize > FILEDUMP_BUFSIZE )
		{
			iReadSize = FILEDUMP_BUFSIZE;
		}
		else
		{
			iReadSize = (int)ulSize;
		}
		
		iReadSize = File_Read(hFile, pubBuf, iReadSize);
		if ( iReadSize <= 0 )
		{
			break;
		}
		ulSize -= iReadSize;
		
		for ( i = 0; i < iReadSize; i++ )
		{
			if ( i % 16 == 0 )
			{
				StdIo_PrintFormat("%08lx: ", ulPos);
			}
			StdIo_PrintFormat("%02x ",  pubBuf[i]);
			ulPos++;
			if ( i % 16 == 15 )
			{
				StdIo_PrintFormat("\n");
			}
		}
	}
	StdIo_PrintFormat("\n");
	
	
	/* メモリ開放 */
	Memory_Free(pubBuf);

	/* ファイルを閉じる */	
	File_Close(hFile);

	return 0;
}


/* end of file */

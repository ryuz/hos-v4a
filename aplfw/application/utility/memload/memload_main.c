/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memload_main.c
 * @brief%jp{メモリロードコマンド}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memload.h"


int MemLoad_Main(int argc, char *argv[])
{
	HANDLE			hFile;
	unsigned long	ulAddr;
	unsigned long	ulSize;
	
	
	if ( argc < 3 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s filename addrress [size]\n\n",
				argv[0]
			);
		return 1;
	}
	
	
	hFile = File_Open(argv[1], FILE_OPEN_EXIST | FILE_OPEN_READ);
	if ( hFile == HANDLE_NULL )
	{
		StdIo_PrintFormat("file open error: %s\n", argv[1]);
		return 1;
	}
	
	ulAddr = strtoul(argv[2], 0, 0);
	
	if ( argc >= 4 )
	{
		ulSize = strtoul(argv[3], 0, 0);
	}
	else
	{
		ulSize = File_Seek(hFile, 0, FILE_SEEK_END);
		File_Seek(hFile, 0, FILE_SEEK_SET);
	}
	
	File_Read(hFile, (void *)ulAddr, ulSize);
	
	File_Close(hFile);
	
	return 0;
}



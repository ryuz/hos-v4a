/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  memsave_main.c
 * @brief %jp{メモリ保存コマンド}
 *
 * Copyright (C) 2006-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memsave.h"


int MemSave_Main(int argc, char *argv[])
{
	HANDLE			hFile;
	unsigned long	ulAddr;
	unsigned long	ulSize;
	
	
	if ( argc < 4 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s filename addrress size\n\n",
				argv[0]
			);
		return 1;
	}
	
	
	hFile = File_Open(argv[1], FILE_OPEN_CREATE | FILE_OPEN_WRITE);
	if ( hFile == HANDLE_NULL )
	{
		StdIo_PrintFormat("file open error: %s\n", argv[1]);
		return 1;
	}
	
	ulAddr = strtoul(argv[2], 0, 0);
	ulSize = strtoul(argv[3], 0, 0);
	
	File_Write(hFile, (void *)ulAddr, ulSize);
	
	File_Close(hFile);
	
	return 0;
}



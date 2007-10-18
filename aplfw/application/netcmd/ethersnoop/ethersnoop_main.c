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
#include "ethersnoop.h"


int EtherSnoop_Main(int argc, char *argv[])
{
	HANDLE			hEther;
	unsigned char	*pubBuf;
	FILE_SIZE		Size;
	FILE_SIZE		i;
	
	if ( argc < 2 )
	{
		return 1;
	}
	
	/* Etherポートを開く */	
	if ( (hEther = File_Open(argv[1], FILE_OPEN_READ)) == HANDLE_NULL )
	{
		return 1;
	}
	
	/* バッファメモリ確保 */
	if ( (pubBuf = Memory_Alloc(4096)) == NULL )
	{
		return 1;
	}
	
	/* 受信 */	
	while ( (Size = File_Read(hEther, pubBuf, 4096)) > 0 )
	{
		for ( i = 0; i < Size; i++ )
		{
			StdIo_PrintFormat("%02x ", pubBuf[i]);
		}
		StdIo_PutChar('\n');
	}
	
	Memory_Free(pubBuf);
	File_Close(hEther);

	return 0;
}



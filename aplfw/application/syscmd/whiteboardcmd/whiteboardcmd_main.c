/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  whiteboardcmd_main.c
 * @brief %jp{ホワイトボード設定コマンド}
 *
 * Copyright (C) 2009 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "whiteboardcmd.h"


int WhiteboardCmd_Main(int argc, char *argv[])
{
	char	szKey[64];
	char	szBuf[64];

	if ( argc < 2 )
	{
		StdIo_PrintFormat(
			"%s <command> <parameters...>\n"
			"  commands\n"
			"    setstr key value\n"
			"    getstr key\n"
			"    delete key\n"
			"    list\n"
			, argv[0]);

		return 1;
	}
	
	if ( strcmp(argv[1], "setstr") == 0 )
	{
		if ( argc >= 4 )
		{
			Whiteboard_SetString(argv[2], argv[3]);
		}
	}
	else if ( strcmp(argv[1], "getstr") == 0 )
	{
		if ( argc >= 3 )
		{
			Whiteboard_GetString(argv[2], szBuf, sizeof(szBuf), "");
			StdIo_PrintFormat("%s\n", szBuf);
		}
	}
	else if ( strcmp(argv[1], "delete") == 0 )
	{
		if ( argc >= 3 )
		{
			Whiteboard_SetString(argv[2], NULL);
		}
	}
	else if ( strcmp(argv[1], "list") == 0 )
	{
		szKey[0] = '\0';
		while ( Whiteboard_GetNextKey(szKey, szKey, sizeof(szKey)) != NULL )
		{
			Whiteboard_GetString(szKey, szBuf, sizeof(szBuf), "");
			StdIo_PrintFormat("%s=%s\n", szKey, szBuf);
		}
	}
	else
	{
		StdIo_PrintFormat("command error\n");
		return 1;
	}
		
	return 0;
}


/* end of file */

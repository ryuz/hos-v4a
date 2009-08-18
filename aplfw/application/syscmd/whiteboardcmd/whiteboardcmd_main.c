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
	char	szBuf[64];

	if ( argc < 3 )
	{
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
		Whiteboard_GetString(argv[2], szBuf, sizeof(szBuf), "");
		StdIo_PrintFormat("%s\n", szBuf);
	}
	else
	{
		return 1;
	}
		
	return 0;
}


/* end of file */

/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  keytest_main.c
 * @brief %jp{キーテストプコマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "keytest.h"


int KeyTest_Main(int argc, char *argv[])
{
	HANDLE hTty;

	StdIo_PutString("\n[KeyTest] start\n");
	hTty = Process_GetTerminal(HANDLE_NULL);

	for ( ; ; )
	{
		int c;
		c = File_GetChar(hTty);
		File_PrintFormat(hTty, "%02x  ", c);
		if ( c >= 0x20 )
		{
			File_PutChar(hTty, c);
		}
		File_PrintFormat(hTty, "\r\n");
		
		if ( c == 'q' || c == 'Q' )
		{
			break;
		}
	}

	StdIo_PutString("\n[KeyTest] quit\n");

	return 0;
}



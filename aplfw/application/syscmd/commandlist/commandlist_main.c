/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  commandlist_main.c
 * @brief %jp{コマンドリストコマンド}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "commandlist.h"


int CommandList_Main(int argc, char *argv[])
{
	COMMAND_PTR	Ptr;
	const char 	*pszName;
		
	/* 最初のコマンドを得る */
	Ptr = Command_GetFirstCommand();
	while ( Ptr != NULL )
	{
		Ptr = Command_GetNextCommand(Ptr, &pszName);
		
		StdIo_PrintFormat("%s\n", pszName);
	}
		
	return 0;
}


/* end of file */

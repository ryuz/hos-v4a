/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  timecmd_main.c
 * @brief %jp{時刻コマンド}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "timecmd.h"


int TimeCmd_Main(int argc, char *argv[])
{
	StdIo_PrintFormat("%ld\n", (long)Time_GetSystemTime());
	
	return 0;
}


/* end of file */

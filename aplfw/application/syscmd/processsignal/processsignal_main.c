/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  processsignal.h
 * @brief %jp{プロセスシグナルコマンド}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "processsignal.h"


int ProcessSignal_Main(int argc, char *argv[])
{
	HANDLE	hProcess;
	int		iSignal = PROCESS_SIGNAL_KILL;
	
	if ( argc < 2 )
	{
		StdIo_PrintFormat(
				"<usage>\n"
				" %s [options] prosesshandle\n\n",
				argv[0]
			);
		return 1;
	}
	
	hProcess = (HANDLE)strtoul(argv[1], NULL, 0);
	
	
	Process_SendSignal(hProcess, iSignal);
	
	
	return 0;
}


/* end of file */

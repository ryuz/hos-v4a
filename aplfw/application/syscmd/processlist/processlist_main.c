/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  processlist.h
 * @brief %jp{プロセスリストコマンド}
 *
 * Copyright (C) 2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "processlist.h"
#include "system/sysapi/sysapi.h"


int ProcessList_Main(int argc, char *argv[])
{
	HANDLE			hProcess;
	unsigned long	ulExecSec;
	unsigned long	ulExecNano;
	int				iIsr   = 0;
	int				i;
	
	/* オプション解析 */
	for ( i = 1; i < argc; i++ )
	{
		if ( strcmp(argv[i], "-i") == 0 )
		{
			iIsr = 1;
		}
	}
	
	/* 表示 */
	StdIo_PutString("HANDLE   PARENT   TIME[s]     +TIME[ns]    COMMAND\n");
	StdIo_PutString("--------+--------+-----------+-----------+-----------\n");

	/* アイドル時間取得 */
	ulExecSec = Process_GetExecutionTime((HANDLE)(-1), &ulExecNano);
	StdIo_PrintFormat("%08lx ", (unsigned long)0);
	StdIo_PrintFormat("%08lx ", (unsigned long)0);
	StdIo_PrintFormat("%11lu ", ulExecSec);
	StdIo_PrintFormat("%11lu ", ulExecNano);
	StdIo_PrintFormat("[idle]");
	StdIo_PutChar('\n');
	
	/* 最初のプロセスを得る */
	hProcess = System_GetNextProcess(HANDLE_NULL);
	while ( hProcess != NULL )
	{
		ulExecSec = Process_GetExecutionTime(hProcess, &ulExecNano);
		StdIo_PrintFormat("%08lx ", (unsigned long)hProcess);
		StdIo_PrintFormat("%08lx ", (unsigned long)Process_GetParentProcess(hProcess));
		StdIo_PrintFormat("%11lu ", ulExecSec);
		StdIo_PrintFormat("%11lu ", ulExecNano);
		StdIo_PrintFormat("%s",     Process_GetCommandLine(hProcess));
		StdIo_PutChar('\n');
		
		hProcess = System_GetNextProcess(hProcess);
	}
	
	/* 割込み処理時間表示 */
	if ( iIsr )
	{
		SYSTIM_CPUTIME	CpuTime;
	
		StdIo_PutString("\n\n");
		StdIo_PutString("INTNUM   TIME[s]     +TIME[ns]  \n");
		StdIo_PutString("--------+-----------+-----------\n");
		for ( i = 0; i < 256; i++ )
		{
			CpuTime = SysInt_GetIntTime(i);
			if ( CpuTime > 0 )
			{
				StdIo_PrintFormat("%8d ", i);
				StdIo_PrintFormat("%11lu ", SysTim_CpuTimeToSecond(CpuTime));
				StdIo_PrintFormat("%11lu\n", SysTim_CpuTimeToNanosecond(CpuTime));
			}
		}
	}
	
	
	return 0;
}


/* end of file */
